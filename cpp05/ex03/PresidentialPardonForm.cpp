#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential", 72, 45), target("default target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("presidential", 72, 45), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToSign() && executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (getSignedAForm() == false)
		throw FormNotSigned();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}