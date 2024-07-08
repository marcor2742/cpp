/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:16:16 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:16:17 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const name;
	bool signedAForm;
	int const gradeToSign;
	int const gradeToExecute;

public:
	AForm();
	AForm(std::string const name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &form);
	virtual ~AForm() {}
	AForm &operator=(const AForm &form);

	std::string getName() const;
	bool getSignedAForm() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "AForm: Grade too high";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw()
    		{
    		    return "AForm: Grade too low";
    		}
	};
	class FormNotSigned : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "AForm: Form not signed";
			}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif