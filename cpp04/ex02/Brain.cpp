#include "Brain.hpp"

Brain::Brain()
{
	std::cout <<GREEN "Brain default constructor called" RESET<< std::endl;
}

Brain::~Brain()
{
	std::cout <<GREEN "Brain destructor called" RESET<< std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout <<GREEN "Brain copy constructor called" RESET<< std::endl;
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout <<GREEN "Brain assignment operator overload called" RESET<< std::endl;
	if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = obj.ideas[i];
        }
    }
    return *this;
}
