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

	std::ifstream file(file_name);
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return;              //throw
	}

	std::string line;
	getline(file, line); // Salta la prima riga
	while (getline(file, line))
	{
		try
		{
			size_t i = line.find(" | ");
			if (!checkDate(line.substr(0, 10)))
			{
				std::string str = "Error: bad input => " + line.substr(0, 10);
				throw std::invalid_argument(str);
			}
			if (i == std::string::npos)
				throw std::invalid_argument("Error: missing |.");
			checkValue(line.substr(i + 3));

			std::string output_date = getClosestDate();
			std::cout << line.substr(0, i) << " => " << input_value << " = " << output_value;
			//std::cout << " (" << output_date << ")";
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	file.close();
}

void BitcoinExchange::setCsv()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return;             //throw
	}

	std::string linea;
	getline(file, linea); // Salta la prima riga
    while (getline(file, linea))
	{
		std::string str = linea.substr(0, 10);
		str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
		input_date = std::strtol(str.c_str(), NULL, 10);
		input_value = std::strtod(linea.substr(11, linea.size() - 11).c_str(), NULL);
		csv.insert(std::pair<int, float>(input_date, input_value));
    }
	
	/*std::map<int, float>::iterator it;
	for (it = csv.begin(); it != csv.end(); ++it)
	{
		std::cout << std::fixed << std::setprecision(2); // Imposta la precisione a 2 cifre decimali
		std::cout << "Chiave: " << it->first << ", Valore: " << it->second << std::endl;
	}*/
	
	file.close();
}

bool BitcoinExchange::checkDate(std::string str)
{
	if (str.size() != 10)
		return false;
	std::string year = str.substr(0, 4);
	if (str.at(4) != '-')
		return false;
	std::string month = str.substr(5, 2);
	if (str.at(7) != '-')
		return false;
	std::string day = str.substr(8, 2);

	int yr = std::strtol(year.c_str(), NULL, 10);
	int mo = std::strtol(month.c_str(), NULL, 10);
	int dy = std::strtol(day.c_str(), NULL, 10);
	if (mo < 1 || mo > 12)
		return false;

	bool isLeapYear = (yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0));

	switch (mo)
	{
    	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    	    if (dy < 1 || dy > 31) return false;
    	    break;
    	case 4: case 6: case 9: case 11:
    	    if (dy < 1 || dy > 30) return false;
    	    break;
    	case 2:
    	    if (isLeapYear) {
    	        if (dy < 1 || dy > 29) return false;
    	    } else {
    	        if (dy < 1 || dy > 28) return false;
    	    }
    	    break;
    	default:
    	    return false;
	}

	str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
	input_date = std::strtol(str.c_str(), NULL, 10);

	return true;
}

void BitcoinExchange::checkValue(std::string str)
{
	char* end;
	if (str.size() == 0)
		throw std::invalid_argument("Error: missing value.");
	if (str.at(0) == '-')
		throw std::invalid_argument("Error: not a positive number.");
	if (str.at(0) == '+')
		str.replace(0, 1, "");
	float vl = std::strtod(str.c_str(), &end);
	if (*end != '\0' || end == str.c_str())
		throw std::invalid_argument("Error: not a number.");

	if (vl < 0)
		throw std::invalid_argument("Error: not a positive number.");
	if (vl > 1000)
		throw std::invalid_argument("Error: too large a number.");

	input_value = vl;
}

std::string BitcoinExchange::getClosestDate()
{
	std::map<int, float>::iterator it = csv.lower_bound(input_date);
	if (it->first != input_date && it != csv.begin())
	{
		--it;
	}
	if (it == csv.begin() && it->first > input_date)
	{
    	throw std::invalid_argument("Error: bitcoin didn't exist yet.");
	}
	output_value = csv[it->first] * input_value;
	
	std::stringstream ss;
	ss << it->first;
	return ss.str().insert(4, "-").insert(7, "-");
}
