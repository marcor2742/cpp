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
		size_t i = line.find(" | ");
		if (i == std::string::npos)
			std::cout << "KO ";       //throw scrivi errore 
		if (!checkDate(line.substr(0, i)))
			std::cout << "KO ";       //throw
		if (!checkValue(line.substr(i + 3)))
			std::cout << "KO " << std::endl;       //throw

		printMoney(line); //parte se non ci sono errori
	}

	file.close();
}

std::string BitcoinExchange::getClosestDate()
{
	std::map<int, float>::iterator it = csv.lower_bound(input_date);
	if (it == csv.begin() && it->first > input_date)
		return "";//
	if (it == csv.end())
	{
		--it;
	}
	std::ostringstream oss;
	oss << it->first;
	return oss.str();
}

void BitcoinExchange::printMoney(std::string line)
{
	(void)line;
	std::string output_date = getClosestDate();
	std::cout << output_date << " | " << input_value << std::endl;
}

bool BitcoinExchange::checkDate(std::string str)
{
	if (str.size() != 10)
		return false; //throw
	std::string year = str.substr(0, 4);
	if (str.at(4) != '-')
		return false; //throw
	std::string month = str.substr(5, 2);
	if (str.at(7) != '-')
		return false; //throw
	std::string day = str.substr(8, 2);

	int yr = std::strtol(year.c_str(), NULL, 10);
	int mo = std::strtol(month.c_str(), NULL, 10);
	int dy = std::strtol(day.c_str(), NULL, 10);
	if (mo < 1 || mo > 12)
		return false; //throw

	bool isLeapYear = (yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0));

	switch (mo)
	{
    	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    	    if (dy < 1 || dy > 31) return false; // throw Giorno non valido
    	    break;
    	case 4: case 6: case 9: case 11:
    	    if (dy < 1 || dy > 30) return false; //throw  Giorno non valido
    	    break;
    	case 2:
    	    if (isLeapYear) {
    	        if (dy < 1 || dy > 29) return false; // throw Giorno non valido in anno bisestile
    	    } else {
    	        if (dy < 1 || dy > 28) return false; // throw Giorno non valido in anno non bisestile
    	    }
    	    break;
    	default:
    	    return false; // throw Mese non valido
	}

	str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
	input_date = std::strtol(str.c_str(), NULL, 10);

	return true;
}

bool BitcoinExchange::checkValue(std::string str)
{
	char* end;
	if (str.size() == 0)
		return false; //throw
	if (str.at(0) == '-')
		return false; //throw
	if (str.at(0) == '+')
		str.replace(0, 1, "");
	float vl = std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return false; //throw
	if (end == str.c_str())
		return false; //throw

	if (vl < 0 || vl > 1000)
		return false; //throw
	input_value = vl;
	return true;
}

/*void BitcoinExchange::checkInput()
{
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
		size_t i = line.find(" | ");
		if (i == std::string::npos)
			std::cout << "KO ";       //throw
		if (checkDate(line.substr(0, i)) == false)
			std::cout << "KO ";       //throw
		else
			std::cout << input_date << " ";
		if (!checkValue(line.substr(i + 3)))
			std::cout << "KO " << std::endl;       //throw
		else
			std::cout << input_value << std::endl;
	}

	file.close();
}*/

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