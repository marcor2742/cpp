#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	type = wronganimal.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "una classe astratta non fa suoni, anche se sbagliata" << std::endl;
}