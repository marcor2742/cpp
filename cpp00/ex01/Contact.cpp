#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created" << std::endl;
}

Contact::~Contact() {}

void	Contact::set_f_name( std::string fName)
{
	this->first_name = fName;
}

std::string		Contact::get_f_name( void )
{
	return (this->first_name);
}