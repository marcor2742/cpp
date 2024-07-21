/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:21:38 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/21 19:21:39 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<int, float> csv; //carta geografica
		int input_date;
		float input_value;
		float output_value;
		char *file_name;
		BitcoinExchange();

	public:
		BitcoinExchange(char *str);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void btc();

		void setCsv();

		bool checkDate(std::string str);
		void checkValue(std::string str);
		std::string getClosestDate();
};

#endif