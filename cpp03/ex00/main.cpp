#include "ClapTrap.hpp"

int main()
{
	ClapTrap gino("gino");
	gino.attack("carlo");
	gino.takeDamage(3);
	gino.beRepaired(1);
	gino.beRepaired(0);
	gino.beRepaired(7);
	gino.beRepaired(1);
	gino.takeDamage(0);
	gino.beRepaired(0);
	gino.attack("carlo");
	gino.takeDamage(10);
	gino.takeDamage(1);
	gino.beRepaired(1234);
	gino.attack("carlo");
	gino.attack("carlo");
	gino.attack("carlo");
	
}