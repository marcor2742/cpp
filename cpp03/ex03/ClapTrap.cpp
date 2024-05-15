#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str) : Name(str), HitPoints(10), EnergyPoints(10), AttackDamage(0), MaxHitPoints(HitPoints)
{
	std::cout << "ClapTrap " << this->Name << " constructed" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->Name << " destructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->HitPoints = obj.HitPoints;
		this->EnergyPoints = obj.EnergyPoints;
		this->AttackDamage = obj.AttackDamage;
		this->MaxHitPoints = obj.MaxHitPoints;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is already dead, stop" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->Name << " take " << amount << " point of damage";
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
		std::cout << "ClapTrap " << this->Name << " non ha EnergyPoint" << std::endl;
		return;
	}
	if (this->HitPoints == 0)
	{
	    std::cout << "ClapTrap " << this->Name << " is dead and can't be resurrected" << std::endl;
	    this->EnergyPoints--;
	    return;
	}
	else if (this->HitPoints == this->MaxHitPoints)
	{
	    std::cout << "ClapTrap " << this->Name << " is already at his peak of Hitpoints" << std::endl;
	    this->EnergyPoints--;
	    return;
	}

	int result = this->MaxHitPoints;
	std::cout << "ClapTrap " << this->Name << " has repaired himself with " << amount << " point";
	if (this->HitPoints + (int)amount >= this->MaxHitPoints)
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

int ClapTrap::getHitPoints()
{
	return this->HitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return this->EnergyPoints;
}

int ClapTrap::getAttackDamage()
{
	return this->AttackDamage;
}