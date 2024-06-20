#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:


public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	AForm *makeForm(std::string form_name, std::string target);

	class WrongFormName : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Intern wrote a wrong form name";
			}

	};
};

#endif	