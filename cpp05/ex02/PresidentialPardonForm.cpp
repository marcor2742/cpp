#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target(0) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{

}