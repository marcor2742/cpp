#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &obj);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const &obj);

	void attack(std::string const &target);
	void guardGate();
};

#endif