/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:16:12 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:16:13 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
	: name("default"), signedAForm(false), gradeToSign(100), gradeToExecute(100) {}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute)
	: name(name), signedAForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &form)
	: name(form.name), signedAForm(form.signedAForm), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {}

AForm &AForm::operator=(const AForm &form)
{
	if (this != &form)
	{
		const_cast<std::string &>(name) = form.name;
		const_cast<int &>(gradeToSign) = form.gradeToSign;
		const_cast<int &>(gradeToExecute) = form.gradeToExecute;
		signedAForm = form.signedAForm;
	}
	return *this;
}

std::string AForm::getName() const 
{
	return name;
}

bool AForm::getSignedAForm() const 
{
	return signedAForm;
}

int AForm::getGradeToSign() const 
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const 
{
	return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (signedAForm == true || bureaucrat.getGrade() <= gradeToSign)
	{
		signedAForm = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << ", sign grade "
          << form.getGradeToSign() << ", exec grade "
          << form.getGradeToExecute() << ", signed "
          << std::boolalpha << form.getSignedAForm();
	return out;
}
