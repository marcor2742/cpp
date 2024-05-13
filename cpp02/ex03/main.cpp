/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:27:33 by marco             #+#    #+#             */
/*   Updated: 2024/05/13 11:24:20 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
	Point a(12.21f, 4.7f);
	Point b(2.21f, 2.43f);
	Point c(2.21f, 6.83f);
	Point toFind(2.20f, 4.0f);

	if (bsp(a, b, c, toFind))
		std::cout << "il punto è contenuto in esso" << std::endl;
	else
		std::cout << "il punto non è contenuto in esso" << std::endl;
}