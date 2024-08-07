/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:15:40 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:15:41 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat mary("mary", 146);

	try
	{
		Bureaucrat john("john", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n" << std::endl;
	}

	Bureaucrat luca("luca", 10);
	std::cout << luca;
	for (int i = 0; true; ++i)
	{
		try
		{
			luca.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n" << std::endl;
			break;
		}
		std::cout << luca.getGrade() << " ";
	}
	Bureaucrat reno(mary);
	std::cout << reno;
	for (int i = 0; true; ++i)
	{
		try
		{
			reno.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n" <<std::endl;
			break;
		}
		std::cout << reno.getGrade() << " ";
	}

	Bureaucrat lisa;
	lisa = luca;
	std::cout << lisa << std::endl;
}