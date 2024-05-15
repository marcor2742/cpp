#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
	DiamondTrap();
public:
	DiamondTrap(std::string str);
	~DiamondTrap();
	DiamondTrap(DiamondTrap const &rhs);
	DiamondTrap &operator=(DiamondTrap const &rhs);

	using ScavTrap::attack;
	void whoAmI();
};

#endif