#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{
private:
	std::string _name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;
	int MaxHitPoints;
	DiamondTrap();
public:
	DiamondTrap(std::string str);
	~DiamondTrap();
	DiamondTrap(DiamondTrap const &rhs);
	DiamondTrap &operator=(DiamondTrap const &rhs);
	void pEnergyPoint();

	using ScavTrap::attack;
	void whoAmI();
};

#endif