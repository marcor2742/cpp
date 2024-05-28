/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:28:34 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/28 16:28:35 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "colours.h"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;
	
public:
	AMateria();
	AMateria(AMateria const &amateria);
	AMateria &operator=(AMateria const &amateria);
	AMateria(std::string const &type);
	virtual ~AMateria();

	std::string const &getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif