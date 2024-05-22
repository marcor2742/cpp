#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(Cure const &copycure);
	Cure &operator=(Cure const &copycure);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif