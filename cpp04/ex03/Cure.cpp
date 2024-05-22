#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const &copycure) : AMateria(copycure)
{
	std::cout << "copy constructor with ";
	*this = copycure;
}

Cure &Cure::operator=(Cure const &copycure)
{
	if (this != &copycure)
	{
		AMateria::operator=(copycure);
	}
	return *this;
}

Amateria *Cure::clone() const
{
	Cure *newobj = new Cure(*this);
	return newobj;
}

void Cure::use(ICharacter &target)
{
	std::cout << "hai usato delle cure, è ricomparsa la tua gamba amputata!" << std::endl;
}