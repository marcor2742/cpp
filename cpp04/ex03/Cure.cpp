/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:29:11 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/28 16:29:12 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const &copycure) : AMateria(copycure)
{
	std::cout << "copy constructor with ";
	*this = copycure;
}

Cure &Cure::operator=(Cure const &copycure)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &copycure)
	{
		AMateria::operator=(copycure);
	}
	return *this;
}

AMateria *Cure::clone() const
{
	Cure *newobj = new Cure(*this);
	return newobj;
}

void Cure::use(ICharacter &target)
{
	std::cout << "usi delle cure su " << target.getName() << ", è ricomparsa la tua gamba amputata!" << std::endl;
}