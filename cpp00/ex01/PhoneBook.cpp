#include <iostream>
#include <string>
#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	this->last_contact = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

void PhoneBook::addValue( void )
{
	std::string tmp;
	Contact	ctmp;
	int i = 0;

	while (i < 5)
	{
		do
		{
			std::cout << ctmp.ContactFields(i) << std::endl;
			if (std::getline(std::cin, tmp).eof())
				throw std::runtime_error("chiudo tutto, scusa!"); // Throw an exception per i try cathc nel main
			ctmp.set_field(tmp, i);
		}
		while (tmp.empty());
		i++;
	}

	this->contacts[this->last_contact % 8] = ctmp;
	this->last_contact++;

}

void PhoneBook::printContacts() {

	std::string tmp;
	std::stringstream num;
	int i;
	int j = 0;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << "   Index  " << "│" << "First Name" << "│" 
		<< " Last Name" << "│" << " Nickname " << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for(i = 0; i < last_contact && i < 8; i++) {
		num.str("");
		num << i + 1;
		std::cout
			<< "│"
			<< this->format_table(num.str())
			<< "│"
        	<< this->format_table(contacts[i].get_field("first_name"))
        	<< "│"
			<< this->format_table(contacts[i].get_field("last_name"))
			<< "│"
			<< this->format_table(contacts[i].get_field("nickname"))
			<< "│" << std::endl;
		if (i + 1 < last_contact && i + 1 < 8)
			std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
    }

	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	
	std::cout << "inserisci l'indice del contatto che vuoi vedere" << std::endl;
	
	do
	{
		if (std::getline(std::cin, tmp).eof())
			throw std::runtime_error("chiudo tutto, scusa!");
		else if (tmp == "1")
			j = 1;
		else if (tmp == "2")
			j = 2;
		else if (tmp == "3")
			j = 3;
		else if (tmp == "4")
			j = 4;
		else if (tmp == "5")
			j = 5;
		else if (tmp == "6")
			j = 6;
		else if (tmp == "7")
			j = 7;
		else if (tmp == "8")
			j = 8;
		if (j == 0 || j > i)
			std::cout << "inserisci un indice valido" << std::endl;
	}
	while (tmp.empty() || j == 0 || j > i);

	std::cout << "First Name: " << contacts[j - 1].get_field("first_name") << std::endl;
	std::cout << "Last Name: " << contacts[j - 1].get_field("last_name") << std::endl;
	std::cout << "Nickname: " << contacts[j - 1].get_field("nickname") << std::endl;
	std::cout << "Phone Number: " << contacts[j - 1].get_field("phonenumber") << std::endl;
	std::cout << "Darkest Secret: " << contacts[j - 1].get_field("darkest_secret") << std::endl;
}

std::string	PhoneBook::format_table( std::string name )
{
	if (name.length() > 10)
	{
		name = name.substr(0, 9);
		name += ".";
	}
	while (name.length() < 10)
		name = " " + name;

	return (name);
}