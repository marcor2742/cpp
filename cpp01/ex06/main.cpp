/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:37:31 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:37:33 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "harl evidentemente ha scritto troppo o si è dimenticato di scrivere un argomento" << std::endl;
		return 1;
	}
	
	Harl obj;
    
	obj.complain(argv[1]);
}