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
	virtual void beSigned(Bureaucrat &bureaucrat) = 0;

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
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif