#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<int, double> csv; //carta geografica
		int input_date;
		double input_value;
		char *file_name;
		BitcoinExchange() {}

	public:
		BitcoinExchange(char *str) : file_name(str) {}
		~BitcoinExchange() {}
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void btc(); //main

		void setCsv(); //ifstream di data.csv 
		/*int toInt(std::string str); //e conversione da string a int e double
		double toDouble(std::string str);

		bool checkInput(std::string str); // split " | " per richiamare checkDate e checkValue
		bool checkDate(std::string str);
		bool checkValue(std::string str);*/
};

#endif