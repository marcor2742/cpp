#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout <<YELLOW "ClapTrap default constructor called" END<< std::endl;
}

ClapTrap::ClapTrap(std::string str) : Name(str), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout <<YELLOW "ClapTrap " END<< this->Name << " constructed" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout <<YELLOW "ClapTrap " END<< this->Name << " destructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->HitPoints = obj.HitPoints;
		this->EnergyPoints = obj.EnergyPoints;
		this->AttackDamage = obj.AttackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout <<YELLOW "ClapTrap " END<< this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}
	std::cout <<YELLOW "ClapTrap " END<< this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->HitPoints == 0)
	{
		std::cout <<YELLOW "ClapTrap " END<< this->Name << " is already dead, stop" << std::endl;
		return;
	}
	std::cout <<YELLOW "ClapTrap " END<< this->Name << " take " << amount << " point of damage";
	if (this->HitPoints <= (int)amount)
	{
		std::cout << " and died" << std::endl;
		this->HitPoints = 0;
	}
	else
	{
		std::cout << " and he has " << this->HitPoints - amount << " HitPoints left" << std::endl;
		this->HitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints == 0)
	{
		std::cout <<YELLOW "ClapTrap " END<< this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}

	switch(this->HitPoints)
	{
		case 0:
			std::cout <<YELLOW "ClapTrap " END<< this->Name << " is dead and can't be resurrected" << std::endl;
			this->EnergyPoints--;
			return;
		case 10:
			std::cout <<YELLOW "ClapTrap " END<< this->Name << " is already at his peak of Hitpoints" << std::endl;
			this->EnergyPoints--;
			return;
		default:
			break;
	}

	int result = 10;
	std::cout <<YELLOW "ClapTrap " END<< this->Name << " has repaired himself with " << amount << " point";
	if (this->HitPoints + amount >= 10)
	{
		this->HitPoints = result;
	}
	else
	{
		result = this->HitPoints + amount;
		this->HitPoints = result;
	}
	std::cout << " and now he has " << result << " HitPoints" << std::endl;
	this->EnergyPoints--;
}