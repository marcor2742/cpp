#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &copyice) : AMateria(copyice)
{
	std::cout << "copy constructor with ";
	*this = copyice;
}

Ice &Ice::operator=(Ice const &copyice)
{
	if (this != &copyice)
	{
		AMateria::operator=(copyice);
	}
	return *this;
}

AMateria *Ice::clone() const
{
	Ice *newobj = new Ice(*this);
	return newobj;
}

void Ice::use(ICharacter &target)
{
	std::cout << "spari del ghiaccio a " << target.getName() << ", il ghiccio si è sciolto prima di colpirlo" << std::endl;
}