#include "PhoneBook.hpp"

int main()
{
	std::string tmp;
	PhoneBook	book;

	try {

		while (true)
		{
			if (std::getline(std::cin, tmp).eof())
			 	break;
			else if (tmp == "ADD")
			{
				book.addValue();
				std::cout << "contatto aggiunto" << std::endl;
			}
			else if (tmp == "SEARCH")
			{
				book.printContacts();
			}
			else if (tmp == "EXIT")
			{
				break;
			}
			else
				std::cout << "inserisci un comando (ADD, SEARCH, EXIT)" << std::endl;

		}

	} catch (const std::runtime_error& e) { //rivedere poi come si usa
        std::cerr << e.what() << std::endl;
        return 1;
    }
	
}

	//std::getline();