/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:38:19 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/15 16:38:20 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << YELLOW;
	ClapTrap gino("gino");
	std::cout << END;
	//for (int i = 0; i < 11; i++)
		gino.attack("luca");
	std::cout << gino.getHitPoints() << std::endl;

	std::cout << CYAN;
	ScavTrap luca("luca");
	std::cout << END;
	//for (int i = 0; i < 51; i++)
		luca.attack("gino");

	std::cout << luca.getHitPoints() << std::endl;

	std::cout << GREEN;
	FragTrap carl("carl");
	std::cout << END;
	//for (int i = 0; i < 101; i++)
		carl.attack("gino");
	std::cout << carl.getHitPoints() << std::endl;
	
	std::cout << std::endl;

	gino.beRepaired(123456);
	gino.takeDamage(2);
	luca.beRepaired(234);
	luca.takeDamage(32);
	luca.guardGate();
	carl.beRepaired(45);
	carl.takeDamage(45);
	carl.highFivesGuys();

	std::cout << std::endl;
	
}