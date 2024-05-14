#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->Name << " destructed" << std::endl;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	std::cout << "ScavTrap " << this->Name << " constructed" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	this->MaxHitPoints = this->HitPoints;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	//*this = obj;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << "ScavTrap " << this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " END<< this->Name << " is now in the useless Gate keeper mode " << std::endl;
}