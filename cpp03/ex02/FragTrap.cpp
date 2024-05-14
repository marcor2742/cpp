#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->Name << " constructed" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	this->MaxHitPoints = this->HitPoints;
}

FragTrap::FragTrap(FragTrap const &rhs) : ClapTrap(rhs) {}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->Name << " destructed" << std::endl;
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
		std::cout << "FragTrap " << this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints--;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->Name << " ti batte il cinque" << std::endl;
}