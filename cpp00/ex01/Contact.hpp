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
	std::string fields[5];
	
	public:
	Contact();
	~Contact();
	std::string		ContactFields( int );
	void			set_field(std::string fName, int i);
    std::string		get_field(std::string name);
    //std::string		get_f_name( void );

};

#endif