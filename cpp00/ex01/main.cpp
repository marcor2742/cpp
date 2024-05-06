/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:33:29 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:33:31 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string tmp;
	PhoneBook	book;

	try {

		while (true)
		{
			if (std::getline(std::cin, tmp).eof())
			 	break;
			else if (tmp == "ADD")
			{
				book.addValue();
				std::cout << "contatto aggiunto" << std::endl;
			}
			else if (tmp == "SEARCH")
			{
				book.printContacts();
			}
			else if (tmp == "EXIT")
			{
				break;
			}
			else
				std::cout << "inserisci un comando (ADD, SEARCH, EXIT)" << std::endl;

		}

	} catch (const std::runtime_error& e) { //rivedere poi come si usa
        std::cerr << e.what() << std::endl;
        return 1;
    }
	
}

	//std::getline();