#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << GREEN "||||||BUREAUCRAT INSTATIATE TESTS||||||\n" RESET << std::endl;

	try {
		std::cout << BLUE "Trying to create a bureaucrat with a grade of 0:" RESET << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " RESET << e.what() << RESET << std::endl;
	}

	try {
		std::cout << BLUE "Trying to create a bureaucrat with a grade of 151:" RESET << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " << RESET << e.what() << std::endl;
	}

	Bureaucrat bureaucrat_0;
	Bureaucrat bureaucrat_1("Jack", 75);

	std::cout << GREEN "\n||||||BUREAUCRAT TESTS||||||\n" RESET << std::endl;

	try {
		std::cout << BLUE "-----Before Decrement-----" RESET << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_0.getGrade() << std::endl;

		std::cout << BLUE "-----After Decrement-----" RESET << std::endl;
		bureaucrat_0.decrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_0.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << BLUE "-----Before Increment-----" RESET << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_1.getGrade() << std::endl;

		std::cout << BLUE "-----After Increment-----" RESET << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_1.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN "\n||||||FORM TESTS||||||\n" RESET << std::endl;

	Bureaucrat High("High", 1);
	Bureaucrat Low("Low", 150);

	// Test case 1: ShrubberyCreationForm
	try
	{
		ShrubberyCreationForm form("garden");
		// form.execute(Bureaucrat("John", 150));
		// form.execute(Bureaucrat("Jane", 137));
		High.executeForm(form);
		High.signForm(form);
		High.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << GREEN "cacca pupu: " RESET << e.what() << std::endl;
	}

	// Test case 2: RobotomyRequestForm
	try
	{
		RobotomyRequestForm form("robot");
		form.execute(Bureaucrat("John", 72));
		form.execute(Bureaucrat("Jane", 45));
	}
	catch (std::exception &e)
	{
		std::cerr << BLUE " lobotomizzati: " RESET << e.what() << std::endl;
	}

	// Test case 3: PresidentialPardonForm
	try
	{
		PresidentialPardonForm form("president");
		form.execute(Bureaucrat("John", 50));
		form.execute(Bureaucrat("Jane", 1));
	}
	catch (std::exception &e)
	{
		std::cerr << CYAN "presidente ? " RESET << e.what() << std::endl;
	}

	return 0;

}