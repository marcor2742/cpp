#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
	Contact contacts[8];
	int last_contact;
	
	public:
	PhoneBook();
	~PhoneBook();
	void 	addValue( void );
};



#endif