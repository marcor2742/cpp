/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:29:19 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/28 16:29:20 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &copyice) : AMateria(copyice)
{
	std::cout << "copy constructor with ";
	*this = copyice;
}

Ice &Ice::operator=(Ice const &copyice)
{
	if (this != &copyice)
	{
		AMateria::operator=(copyice);
	}
	return *this;
}

AMateria *Ice::clone() const
{
	Ice *newobj = new Ice(*this);
	return newobj;
}

void Ice::use(ICharacter &target)
{
	std::cout << "spari del ghiaccio a " << target.getName() << ", il ghiccio si è sciolto prima di colpirlo" << std::endl;
}