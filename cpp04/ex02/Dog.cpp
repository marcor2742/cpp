#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &obj) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignation operator called" << std::endl;
	type = obj.type;
	this->brain = new Brain(*obj.getBrain());
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}