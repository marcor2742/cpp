/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:15:51 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:15:52 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

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
	void signForm(Form &form);

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