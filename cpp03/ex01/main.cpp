//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap gino("gino");
	gino.attack("luca");
	ScavTrap luca("luca");
	luca.attack("gino");
	
	gino.beRepaired(123456);
	gino.takeDamage(2);
	luca.beRepaired(234);
	luca.takeDamage(32);
	luca.guardGate();
	
}