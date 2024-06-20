#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern&){}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern&) 
{
	return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (form_name == forms[i])
			{
				switch (i)
				{
					case 0:
						return new PresidentialPardonForm(target);
					case 1:
						return new RobotomyRequestForm(target);
					case 2:
						return new ShrubberyCreationForm(target);
				}
			}
		}
		throw WrongFormName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return NULL;
	}
}
