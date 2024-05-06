/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:37:17 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:37:19 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "------------vivo------------" << std::endl;
}

Harl::~Harl()
{
	std::cout << "------------morto-----------" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	std::string levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (level != levelArray[i] && i < 4)
		i++;
	switch (i)
	{
        case 0:
            Harl::debug();
			std::cout << std::endl;
        case 1:
			Harl::info();
			std::cout << std::endl;
        case 2:
			Harl::warning();
			std::cout << std::endl;
		case 3:
			Harl::error();
			std::cout << std::endl;
			break;
        default:
            std::cout << "insignificant problems" << std::endl;
    }
}