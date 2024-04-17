#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <sstream>

class PhoneBook
{
	private:
	Contact contacts[8];
	int last_contact;
	
	public:
	PhoneBook();
	~PhoneBook();
	void 	addValue( void );
	void	printContacts();
	std::string		format_table( std::string name );
};



#endif