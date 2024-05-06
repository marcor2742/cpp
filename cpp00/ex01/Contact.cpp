/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:33:09 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:33:11 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created" << std::endl;
	this->fields[0] = "first_name:";
	this->fields[1] = "last_name:";
	this->fields[2] = "nickname:";
	this->fields[3] = "phonenumber:";
	this->fields[4] = "darkest_secret:";
}

Contact::~Contact() {
	std::cout << "Contact destroyed" << std::endl;
}

std::string		Contact::ContactFields( int i )
{
	return (this->fields[i]);
}

void	Contact::set_field(std::string name, int i)
{
	if (this->ContactFields(i) == "first_name:")
		this->first_name = name;
	if (this->ContactFields(i) == "last_name:")
		this->last_name = name;
	if (this->ContactFields(i) == "nickname:")
		this->nickname = name;
	if (this->ContactFields(i) == "phonenumber:")
		this->phonenumber = name;
	if (this->ContactFields(i) == "darkest_secret:")
		this->darkest_secret = name;
}

std::string	Contact::get_field(std::string string)
{
	if (string == "first_name")
		return (this->first_name);
	if (string == "last_name")
		return (this->last_name);
	if (string == "nickname")
		return (this->nickname);
	if (string == "phonenumber")
		return (this->phonenumber);
	if (string == "darkest_secret")
		return (this->darkest_secret);
	return ("");
}

// std::string		Contact::get_f_name( void )
// {
// 	return (this->first_name);
// }