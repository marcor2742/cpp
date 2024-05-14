#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string str);

};

#endif