#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &copyice)
{
	std::cout << "copy constructor with ";
	*this = copyice;
}

Ice &Ice::operator=(Ice const &copyice)
{
	if (this != &copyice)
	{
		AMateria::operator=(copyice)
	}
	return *this;
}

Amateria *Ice::clone() const
{
	Ice *newobj = new Ice(*this);
	return newobj;
}

void Ice::use(ICharacter &target)
{
	std::cout << "hai usato del ghiaccio, si è sciolto" << std::endl;
}