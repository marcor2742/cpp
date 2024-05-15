/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:42:32 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/15 02:27:00 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Yes! i'm \033[97mDiamondTrap\033[0m " << name << std::endl;
	this->Name = name;
	this->ClapTrap::Name = name + "_clap_name";

	FragTrap::HitPoints = 100;
	ScavTrap::EnergyPoints = 50;
	ScavTrap::AttackDamage = 30;

}
/*DiamondTrap::DiamondTrap(DiamondTrap const & rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "Copy constructor for \033[97mDiamondTrap\033[0m called" << std::endl;
	*this = rhs;
}*/

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "Assignation operator for \033[97mDiamondTrap\033[0m called" << std::endl;
	this->Name = rhs.Name;
	this->HitPoints = rhs.HitPoints;
	this->EnergyPoints = rhs.EnergyPoints;
	this->AttackDamage = rhs.AttackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[97mDiamondTrap\033[0m " << this->Name << " is dead" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->Name << " and my ClapTrap name is " << this->ClapTrap::Name << std::endl;
}