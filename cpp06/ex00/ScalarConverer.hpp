/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:41:47 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/12 12:17:14 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	static std::string checkCharString(std::string &str);
    static bool checkPseudoLiteral(std::string &str);
    static void convertChar(std::string &str, int &c, std::stringstream &ss, std::string &literal);
    static void convertInt(int &i, std::stringstream &ss, std::string &literal, bool *isinf);
    static void convertFloat(float &f, std::stringstream &ss, std::string &literal, bool *isinf);
    static void convertDouble(double &d, std::stringstream &ss, std::string &literal, bool *isinf);

public:
	~ScalarConverter();
	static void convert(std::string &literal);

	class NotDisplayable : public std::exception
	{
		public:
			const char *what() const throw() { return "not displayable"; }
	};

	class Impossible : public std::exception
	{
		public:
			const char *what() const throw() { return "impossible"; }
	};

	class OutOfBounds : public std::exception
	{
		public:
			const char *what() const throw() { return "out of bounds"; }
	};

	class PlusInfinity : public std::exception
	{
		public:
			const char *what() const throw() { return "+inf"; }
	};

	class MinusInfinity : public std::exception
	{
		public:
			const char *what() const throw() { return "-inf"; }
	};

	class NotANumber : public std::exception
	{
		public:
			const char *what() const throw() { return "nan"; }
	};

};

#endif
