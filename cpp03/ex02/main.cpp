//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap gino("gino");
	gino.attack("luca");
	ScavTrap luca("luca");
	luca.attack("gino");
	FragTrap carl("carl");
	luca.attack("carl");
	
	gino.beRepaired(123456);
	gino.takeDamage(2);
	luca.beRepaired(234);
	luca.takeDamage(32);
	luca.guardGate();
	carl.beRepaired(45);
	carl.takeDamage(45);
	carl.highFivesGuys();
	
}