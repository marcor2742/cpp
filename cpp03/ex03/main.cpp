//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
/*
	std::cout << YELLOW;
	ClapTrap gino("gino");
	std::cout << END;
	//for (int i = 0; i < 11; i++)
		gino.attack("luca");
	std::cout << gino.getHitPoints() << std::endl;
	std::cout << gino.getEnergyPoints() << std::endl;
	std::cout << gino.getAttackDamage() << std::endl;

	std::cout << CYAN;
	ScavTrap luca("luca");
	std::cout << END;
	//for (int i = 0; i < 51; i++)
		luca.attack("gino");
	std::cout << luca.getHitPoints() << std::endl;
	std::cout << luca.getEnergyPoints() << std::endl;
	std::cout << luca.getAttackDamage() << std::endl;

	std::cout << GREEN;
	FragTrap carl("carl");
	std::cout << END;
	//for (int i = 0; i < 101; i++)
		carl.attack("gino");
	std::cout << carl.getHitPoints() << std::endl;
	std::cout << carl.getEnergyPoints() << std::endl;
	std::cout << carl.getAttackDamage() << std::endl;
*/
	std::cout << MAGENTA;
	DiamondTrap erik("erik");
	std::cout << erik.getHitPoints() << std::endl;
	std::cout << erik.getEnergyPoints() << std::endl;
	std::cout << erik.getAttackDamage() << std::endl;
	std::cout << END;
	//for (int i = 0; i < 51; i++)
		erik.attack("gino");


	
	//std::cout << std::endl;
//
	//gino.beRepaired(123456);
	//gino.takeDamage(2);
	//luca.beRepaired(234);
	//luca.takeDamage(32);
	//luca.guardGate();
	//carl.beRepaired(45);
	//carl.takeDamage(45);
	//carl.highFivesGuys();
//
	std::cout << std::endl;

	erik.takeDamage(45);
	erik.beRepaired(45);
	erik.guardGate();
	erik.highFivesGuys();
	erik.whoAmI();

	std::cout << std::endl;
	
}