/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:33:48 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:33:50 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <sstream>

class PhoneBook
{
	private:
	Contact contacts[8];
	int last_contact;
	
	public:
	PhoneBook();
	~PhoneBook();
	void 	addValue( void );
	void	printContacts();
	std::string		format_table( std::string name );
};



#endif