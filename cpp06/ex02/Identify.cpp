/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:42:25 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 15:42:26 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base	*generate(void) 
{
	int r = std::rand() % 3;
	switch (r)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
	{
		std::cout << "ciao" << std::endl;
		return NULL;
	}
	}
}

void identify_from_pointer(Base *p) {
    if (dynamic_cast<A*>(p))
		std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "bad_cast";
}

void identify_from_reference(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (std::bad_cast&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
	} catch (std::bad_cast&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	} catch (std::bad_cast&) {}
}
