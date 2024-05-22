#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(Ice const &copyice);
	Ice &operator=(Ice const &copyice);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif