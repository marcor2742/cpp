#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

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
				return "char not displayable";
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

	static void convert(std::string &literal)
	{
		int c;
        int i;
        float f;
        double d;

        std::stringstream ss(literal);

		try
		{
        	ss >> c;
			if (ss.fail() || c <= 32 || c >= 126)
				throw Impossible();
			else
        		std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

        ss.clear();
        ss.str(literal);
        ss >> i;
        std::cout << "int: " << i << std::endl;

        ss.clear();
        ss.str(literal);
        ss >> f;
        std::cout << "float: " << f << "f" << std::endl;

        ss.clear();
        ss.str(literal);
        ss >> d;
        std::cout << "double: " << d << std::endl;
	}
};

#endif