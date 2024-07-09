/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:41:51 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 15:41:52 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverer.hpp"

	std::string ScalarConverter::checkCharString(std::string &str)
	{
		double d;

		if (str.size() == 1 && ((str[0] >= '!' && str[0] <= '/') || (str[0] >= ':' && str[0] <= '~')))
		{
			std::cout << str << " is a char" << std::endl;
			return "char";
		}
		for (std::string::size_type i = 0; i < str.size(); ++i)
		{
			char c = str[i];
			if (!((c >= '0' && c <= '9') || c == 'f' || c == '.' || c == '-' || c == '+'))
				return "";
		}

		std::stringstream ss(str);
		ss.str(str);
		ss >> d;
		ss.clear();

		if (str.find(".") == std::string::npos && str.find("f") == std::string::npos && str.size() <= 12 && d <= 2147483647 && d >= -2147483648)
		{
			std::cout << str << " is a int" << std::endl;
			return "int";
		}
		else if (str.find("f") == std::string::npos)
		{
			if (d == std::numeric_limits<double>::max() || d == -std::numeric_limits<double>::max() || d <= std::numeric_limits<double>::min())
				return "infinity";
			std::cout << str << " is a double" << std::endl;
			return "double";
		}
		else
		{
			std::cout << str << " is a float" << std::endl;
			return "float";
		}
		return "";
	}

	bool ScalarConverter::checkPseudoLiteral(std::string &str)
	{
		std::string pseudoarray[8] = {"nan", "nanf", "+inf", "+inff", "inf", "inff", "-inf", "-inff"};
		for (int i = 0; i < 8; i++)
		{
			if (str == pseudoarray[i])
			{
				if (i == 0 || i == 1)
					std::cout << "char: impossible" << "\n"
						<< "int: impossible" << "\n"
						<< "float: nanf" << "\n"
						<< "double: nan" << std::endl;
				if (i >= 2)
				{
					int tmp = 0;
					int tmpf = 0; 
					if (i % 2 != 0)
						tmp = -1;
					else
						tmpf = + 1;
					std::cout << "char: impossible" << "\n"
						<< "int: impossibile" << "\n"
						<< "float: " << pseudoarray[i + tmpf] << "\n"
						<< "double: " << pseudoarray[i + tmp] << std::endl;
				}
				return true;
			}
		}
		return false;
	}

	void ScalarConverter::convertChar(std::string &str, int &c, std::stringstream &ss, std::string &literal)
	{
		if (str == "char")
		{
        	std::cout << "char: " << "'" << literal << "'" << std::endl;
			c = static_cast<int>(literal[0]);
			std::stringstream converter;
        	converter << c;
        	literal = converter.str();
		}
		else
		{
			try
			{
        		ss >> c;
				if (ss.fail() || c < 0 || c > 127)
					throw Impossible();
				if (c <= 32 || c >= 126)
					throw NotDisplayable();
        		std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "char: " << e.what() << '\n';
			}
        	ss.clear();
		}
	}

	void ScalarConverter::convertInt(int &i, std::stringstream &ss, std::string &literal, bool *isinf)
	{
		try
		{
			ss.str(literal);
			ss >> i;
			if (isinf[0] == true || isinf[1] == true)
				throw Impossible();
			if (((i == 2147483647 && literal != "2147483647") || (i == -2147483648 && literal != "-2147483648")))
				throw OutOfBounds();
			std::cout << "int: " << i << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "int: " << e.what() << '\n';
		}
		ss.clear();
	}

	void ScalarConverter::convertFloat(float &f, std::stringstream &ss, std::string &literal, bool *isinf)
	{
		std::string desinenza;

		try
		{
			ss.str(literal);
			ss >> f;
			desinenza = "f";
			if (isinf[0] == true)
				throw PlusInfinity();
			if (isinf[1] == true)
				throw MinusInfinity();
			if ((f == std::numeric_limits<float>::max() && literal.length() > 38) || (f == -std::numeric_limits<float>::max() && literal.length() > 38))
				{
					desinenza = "";
					throw OutOfBounds();
				}
			if (literal.size() <= 6 && (literal.find(".") == std::string::npos || literal.find(".0") != std::string::npos))
				desinenza = ".0f";
			std::cout << "float: " << f << desinenza << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "float: " << e.what() << desinenza << '\n';
		}
	}

	void ScalarConverter::convertDouble(double &d, std::stringstream &ss, std::string &literal, bool *isinf)
	{
		std::string desinenza;

		try
        {
		ss.clear();
        ss.str(literal);
        ss >> d;
		desinenza = "";
		if (literal.size() <= 6 && (literal.find(".") == std::string::npos || literal.find(".0") != std::string::npos))
			desinenza = ".0";
		if (isinf[0] == true)
			throw PlusInfinity();
		if (isinf[1] == true)
			throw MinusInfinity();
        std::cout << "double: " << d << desinenza << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "double: " << e.what() << '\n';
		}
	}

	void ScalarConverter::convert(std::string &literal)
	{
		int c;
        int i;
        float f;
        double d;
		bool isinf[2] = {false, false};

		if (checkPseudoLiteral(literal) == true)
			return;
		std::string str = checkCharString(literal);
		if (str == "")
		{
			std::cout << "bad input" << std::endl;
			return;
		}

		std::stringstream ss(literal);
		convertChar(str, c, ss, literal);
		ss.str(literal);
		ss >> d;
		if (d == std::numeric_limits<double>::max() && literal.length() > 308)
			isinf[0] = true;
		if (d == -std::numeric_limits<double>::max() && literal.length() > 308)
			isinf[1] = true;
		ss.clear();
		convertInt(i, ss, literal, isinf);
		convertFloat(f, ss, literal, isinf);
		convertDouble(d, ss, literal, isinf);
	}