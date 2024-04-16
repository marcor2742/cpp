#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created" << std::endl;
	this->tmp[0] = "first_name:";
	this->tmp[1] = "last_name:";
	this->tmp[2] = "nickname:";
	this->tmp[3] = "phonenumber:";
	this->tmp[4] = "darkest_secret:";
}

Contact::~Contact() {}

std::string		Contact::stringaArray( int i )
{
	//check se i > 4
	return (this->tmp[i]);
}

void	Contact::set_f_name( std::string fName)
{
	this->first_name = fName;
}

std::string		Contact::get_f_name( void )
{
	return (this->first_name);
}