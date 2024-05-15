#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define MAGENTA "\033[0;35m"
#define END "\033[0m"

class ClapTrap
{
protected:
	std::string Name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;
	int MaxHitPoints;
public:
	ClapTrap();
	ClapTrap(std::string str);
	ClapTrap(const ClapTrap &obj);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &obj);
	int getHitPoints();
	int getEnergyPoints();
	int getAttackDamage();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif