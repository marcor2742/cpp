#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	csv = copy.csv;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		csv = copy.csv;
	return *this;
}

void BitcoinExchange::btc()
{
	setCsv();




}

void BitcoinExchange::setCsv()
{
	std::ifstream file(file_name);
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return;
	}

	std::string linea;
    while (getline(file, linea))
	{
		date = linea.substr(0, 10);
		value = std::stod(linea.substr(11, linea.size() - 11));
        std::cout << linea << std::endl;
    }
	
	
	
	file.close();
}