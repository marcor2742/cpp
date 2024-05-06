/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:35:17 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 12:16:36 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie()
{
    std::cout << this->_name << " si è dissolto nell'acido" << std::endl;
}

void Zombie::setName(std::string name){
    Zombie::_name = name;
}

void Zombie::announce( void ){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
