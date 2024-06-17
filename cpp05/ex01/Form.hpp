#ifndef FORM_HPP
#define FORM_HPP


class Bureaucrat;

#include <iostream>
#include <string>

class Form
{
private:
	std::string const name;
	bool signedForm;
	int const gradeToSign;
	int const gradeToExecute;

public:
	Form();
	Form(std::string const name, int gradeToSign, int gradeToExecute);
	Form(const Form &form);
	~Form() {}
	Form &operator=(const Form &form);

	std::string getName() const;
	bool getSignedForm() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);
	void signForm();

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Grade too high";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw()
    		{
    		    return "Grade too low";
    		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif