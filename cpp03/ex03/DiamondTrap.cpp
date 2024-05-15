#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap() {};

DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_trap"), ScavTrap(str + "_scav_trap"), FragTrap(str + "_frag_trap")
{
	this->_name = str;
	std::cout << "DiamondTrap " << this->_name << " constructed" << std::endl;
	this->ClapTrap::Name = str + "_clap_name";

	FragTrap::HitPoints = 100;
	ScavTrap::EnergyPoints = 50;
	ScavTrap::AttackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " and Claptrap " << ClapTrap::Name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs) {}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}