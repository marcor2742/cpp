#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string str) : ScavTrap(str), FragTrap(str)
{
	this->_name = str;
	std::cout << "DiamondTrap " << this->_name << " constructed" << std::endl;
	this->FragTrap::HitPoints = this->FragTrap::HitPoints;
	this->ScavTrap::EnergyPoints = this->ScavTrap::EnergyPoints;
	this->FragTrap::AttackDamage = this->FragTrap::AttackDamage;
	this->ScavTrap::MaxHitPoints = this->ScavTrap::MaxHitPoints;
}