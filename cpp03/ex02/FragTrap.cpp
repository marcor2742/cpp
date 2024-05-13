#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout <<GREEN "FragTrap default constructor called" END<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout <<GREEN "FragTrap " END<< this->Name << " constructed" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &rhs) : ClapTrap(rhs) {}

FragTrap::~FragTrap()
{
	std::cout <<GREEN "FragTrap " END<< this->Name << " destructed" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

void FragTrap::attack(std::string const &target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout <<GREEN "FragTrap " END<< this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}
	std::cout <<GREEN "FragTrap " END<< this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints--;
}

void FragTrap::highFivesGuys()
{
	std::cout <<GREEN "FragTrap " END<< this->Name << " ti batte li cinque" << std::endl;
}