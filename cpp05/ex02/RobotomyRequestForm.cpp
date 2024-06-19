#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target(0) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{

}