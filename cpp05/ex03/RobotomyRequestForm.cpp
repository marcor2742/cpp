/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:17:49 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 01:17:50 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy", 25, 5), target("default target") 
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("robotomy", 25, 5), target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToSign() && executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (getSignedAForm() == false)
		throw FormNotSigned();

	std::cout << "VRRRR⢀⡦RR⣿⣄⣀⡠RRRRRRR⣀⡦⡠RR" << std::endl;
	if (rand() < RAND_MAX / 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy of " << target << " failed." << std::endl;
}