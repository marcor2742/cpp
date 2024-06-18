#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
	: name("default"), signedForm(false), gradeToSign(100), gradeToExecute(100) {}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
	: name(name), signedForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
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

Form::Form(const Form &form)
	: name(form.name), signedForm(form.signedForm), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
	{
		const_cast<std::string &>(name) = form.name;
		const_cast<int &>(gradeToSign) = form.gradeToSign;
		const_cast<int &>(gradeToExecute) = form.gradeToExecute;
		signedForm = form.signedForm;
	}
	return *this;
}

std::string Form::getName() const 
{
	return name;
}

bool Form::getSignedForm() const 
{
	return signedForm;
}

int Form::getGradeToSign() const 
{
	return gradeToSign;
}

int Form::getGradeToExecute() const 
{
	return gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (signedForm == true || bureaucrat.getGrade() <= gradeToSign)
	{
		signedForm = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}