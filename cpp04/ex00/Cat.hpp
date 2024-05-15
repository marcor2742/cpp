#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Animal.hpp"

class Cat : public Animal
{
protected:
	std::string type;
public:
	Cat();
	~Cat();
};

#endif