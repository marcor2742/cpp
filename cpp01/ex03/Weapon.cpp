/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:36:32 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:36:34 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string str) : type(str)
{
    std::cout << "l'arma " << this->type << " è stata creata" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "oh no, si è rotta l'arma" << std::endl;
}

const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string str)
{
    this->type = str;
}
