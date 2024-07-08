/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:17:26 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:17:27 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	AForm	*Form[3];
	Form[0] = new PresidentialPardonForm(target);
	Form[1] = new RobotomyRequestForm(target);
	Form[2] = new ShrubberyCreationForm(target);

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (form_name == forms[i])
			{
				for (int idx = 0 ; idx < 3 ; idx++)
				{
					if (idx != i)
						delete Form[idx];
				}
				return Form[i];
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
