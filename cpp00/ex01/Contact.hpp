#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phonenumber;
	std::string darkest_secret;

	public:
	Contact();
	~Contact();
	void			set_f_name(std::string fName);
	std::string		get_f_name( void );

};

#endif