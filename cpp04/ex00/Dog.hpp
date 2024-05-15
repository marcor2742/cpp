#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Animal.hpp"

class Dog : public Animal
{
protected:
	std::string type;
public:
	Dog();
	~Dog();
};

#endif