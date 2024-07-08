/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:16:02 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:16:03 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << GREEN "||||||BUREAUCRAT INSTATIATE TESTS||||||\n" RESET << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Exception: " RESET << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Exception: " << RESET << e.what() << std::endl;
	}

	Bureaucrat bureaucrat_0;
	Bureaucrat bureaucrat_1("Jack", 75);

	std::cout << GREEN "\n||||||BUREAUCRAT TESTS||||||\n" RESET << std::endl;

	try
	{
		std::cout << BLUE "-----Before Decrement-----" RESET << std::endl;
		std::cout << bureaucrat_0;

		std::cout << BLUE "-----After Decrement-----" RESET << std::endl;
		bureaucrat_0.decrementGrade();
		std::cout << bureaucrat_0;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << BLUE "-----Before Increment-----" RESET << std::endl;
		std::cout << bureaucrat_1;

		std::cout << BLUE "-----After Increment-----" RESET << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << bureaucrat_1;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN "\n||||||FORM TESTS||||||\n" RESET << std::endl;

	Form form_0;
	Form form_1("Form_1", 80, 80);

	try
	{
		std::cout << BLUE "-----Trying to sign-----" RESET << std::endl;
		std::cout << form_0 << std::endl;
		std::cout << bureaucrat_0;

		bureaucrat_0.signForm(form_0);
		form_0.beSigned(bureaucrat_1);
	}
	catch (std::exception &e)
	{
		std::cerr << RESET RED "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << BLUE "-----signing-----" RESET << std::endl;
		bureaucrat_1.signForm(form_1);
	}
	catch (std::exception &e)
	{
		std::cerr << RESET RED "Exception: " << e.what() << RESET << std::endl;
	}
}