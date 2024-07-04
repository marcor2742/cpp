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
		BitcoinExchange() {}

	public:
		BitcoinExchange(char *str) : file_name(str) {}
		~BitcoinExchange() {}
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void btc();

		void setCsv();

		bool checkDate(std::string str);
		void checkValue(std::string str);
		std::string getClosestDate();
};

#endif