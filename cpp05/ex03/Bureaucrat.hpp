/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:17:22 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:17:23 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	~Bureaucrat() {}

	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade(); //-1
	void decrementGrade(); //+1
	void signForm(AForm &form);

	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw(); //not inline
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw() //inline
    		{
    		    return "Grade too low";
    		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif