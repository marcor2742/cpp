#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap() {};

DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_trap"), FragTrap(str + "_clap_trap"), ScavTrap(str + "_clap_trap")
{
	this->_name = str;
	std::cout << "DiamondTrap " << this->_name << " constructed" << std::endl;
	this->ClapTrap::Name = _name + "_clap_name";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " and Claptrap " << ClapTrap::Name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs) : ClapTrap(rhs) {}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}