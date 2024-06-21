#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class ScalarConverter
{
private:
	ScalarConverter() {}
	ScalarConverter(const ScalarConverter& other) { *this = other; }
	ScalarConverter& operator=(const ScalarConverter& other) { (void)other; return *this; }

public:
	~ScalarConverter() {}

	class NotDisplayable : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "not displayable";
			}
	};

	class Impossible : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "impossible";
			}
	};

	class OutOfBounds : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "out of bounds";
			}
	};

	static std::string checkCharString(std::string &str)
	{
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
		if (str.find(".") == std::string::npos && str.find("f") == std::string::npos)
		{
			std::cout << str << " is a int" << std::endl;
			return "int";
		}
		else if (str.find("f") == std::string::npos)
		{
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

	static void convert(std::string &literal)
	{
		int c;
        int i;
        float f;
        double d;
		std::string desinenza;

		std::string str = checkCharString(literal);
		if (str == "") //42.6 non fa * //nan +inf -inf
		{
			std::cout << "bad input" << std::endl;
			return;
		}

		std::stringstream ss(literal);

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
				if (ss.fail())
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
		
		try
		{
			ss.str(literal);
			ss >> i;
			if (((i == 2147483647 && literal != "2147483647") || (i == -2147483648 && literal != "-2147483648")))
				throw OutOfBounds();
			std::cout << "int: " << i << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << "int: " << e.what() << '\n';
		}
		ss.clear();
		

		ss.str(literal);
		ss >> f;
		desinenza = "f";
		if ((literal.find(".") == std::string::npos || literal.find(".0")) && literal.size() <= 6)
			desinenza = ".0f";
		std::cout << "float: " << f << desinenza << std::endl;	
		

        ss.clear();
        ss.str(literal);
        ss >> d;
		desinenza = "";
		if (literal.find(".") == std::string::npos && literal.size() <= 6)
			desinenza = ".0";
        std::cout << "double: " << d << desinenza << std::endl;
	}
};

#endif
