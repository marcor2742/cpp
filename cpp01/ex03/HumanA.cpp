/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:35:49 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:35:51 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &obj) : name(str), weapon(obj)
{
    std::cout << this->name << " è Americano" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << this->name << " è morto in una sparatoria" << std::endl;  //mettere nome
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
