#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	type = obj.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Moo" << std::endl;
}