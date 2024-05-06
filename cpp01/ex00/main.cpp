/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:34:26 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:34:27 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    randomChump("gino");
    Zombie *allocatedZombie = newZombie("ciro");

    (*allocatedZombie).announce();
    delete (allocatedZombie);
    return(0);
}