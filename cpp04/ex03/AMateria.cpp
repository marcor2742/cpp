/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:28:29 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/28 16:28:30 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("error")
{
	std::cout << "do not use AMateria default constructor" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &amateria)
{
	std::cout << "copy constructor with ";
	*this = amateria;
}

AMateria &AMateria::operator=(AMateria const &amateria)
{
	std::cout << "Amateria assignation operator called" << std::endl;
	if (this != &amateria)
	{
		type = amateria.type;
	}
	return *this;
}


AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "ma certo, usa un materiale astratto su " << target.getName() << std::endl;

}