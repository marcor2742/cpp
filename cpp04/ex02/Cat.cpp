#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &obj) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignation operator called" << std::endl;
	type = obj.type;
	this->brain = new Brain(*obj.getBrain());
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}