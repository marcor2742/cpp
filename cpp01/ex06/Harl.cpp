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
	std::string levelArray[4] = {"debug", "info", "warning", "error"};
	void (Harl::*funcArray[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while (level != levelArray[i] && i < 4)
		i++;
	if (i < 4)
	{
		(this->*funcArray[i])();
		std::cout << std::endl;
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}