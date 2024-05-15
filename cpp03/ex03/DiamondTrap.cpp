#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap() {};

DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_trap"), ScavTrap(str + "_scav_trap"), FragTrap(str + "_frag_trap")
{
	std::cout << "DiamondTrap " << this->_name << " constructed" << std::endl;
	std::cout << ScavTrap::HitPoints << std::endl;
	std::cout << ScavTrap::EnergyPoints << std::endl;
	std::cout << ScavTrap::AttackDamage << std::endl;
	std::cout << ScavTrap::MaxHitPoints << std::endl;
	std::cout << FragTrap::HitPoints << std::endl;
	std::cout << FragTrap::EnergyPoints << std::endl;
	std::cout << FragTrap::AttackDamage << std::endl;
	std::cout << FragTrap::MaxHitPoints << std::endl;
	this->_name = str;
	this->ClapTrap::Name = _name + "_clap_name";
	this->HitPoints = FragTrap::HitPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    this->MaxHitPoints = ScavTrap::MaxHitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
	std::cout << "DiamondTrap " << this->_name << std::endl;
	std::cout << this->HitPoints << std::endl;
	std::cout << this->EnergyPoints << std::endl;
	std::cout << this->AttackDamage << std::endl;
	std::cout << this->MaxHitPoints << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " and Claptrap " << ClapTrap::Name << std::endl;
}

void DiamondTrap::pEnergyPoint()
{
    std::cout << "ScavTrap::EnergyPoint = " << ScavTrap::EnergyPoints << std::endl;
}

//DiamondTrap::DiamondTrap(DiamondTrap const &rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs) {}

/*DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}*/