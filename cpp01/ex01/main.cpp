/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:34:57 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 12:14:49 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie* horde = zombieHorde( 9, "lorenzo" );

    for(int i = 0; i < 9; i++) {
        horde[i].announce();
    }

    delete [] horde;
}