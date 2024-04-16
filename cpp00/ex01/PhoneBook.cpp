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

	do
	{
		std::cout << ctmp.stringaArray(i) <<std::endl;
		std::cin >> tmp;
		ctmp.set_f_name(tmp);
	}
	while (tmp.empty());

	this->contacts[this->last_contact++] = ctmp;




}