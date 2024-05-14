#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;
	DiamondTrap();
	using ScavTrap::HitPoints;
	using ScavTrap::EnergyPoints;
	using FragTrap::AttackDamage;
	using ScavTrap::MaxHitPoints;
public:
	DiamondTrap(std::string str);
	void attack(const std::string& target);
	~DiamondTrap();
	DiamondTrap(DiamondTrap const &rhs);
	DiamondTrap &operator=(DiamondTrap const &rhs);

	using ScavTrap::attack;
	void whoAmI();
};

#endif