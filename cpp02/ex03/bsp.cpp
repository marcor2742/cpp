/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:28:00 by marco             #+#    #+#             */
/*   Updated: 2024/05/12 18:39:58 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed checkTrinagle(Point const &a, Point const &b, Point const &c)
{
	Fixed result;

	result = ( a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()) ) / Fixed(2);
	
	if (result.getRawBits() < 0) {
        result = result * Fixed(-1);  // Converti -1 in Fixed e moltiplica il risultato per -1
    }
	return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void)point;
	Fixed A = checkTrinagle(a, b, c);
    Fixed A1 = checkTrinagle(a, b, point);
    Fixed A2 = checkTrinagle(b, c, point);
    Fixed A3 = checkTrinagle(c, a, point);

	Fixed tolerance(0.01f);
	Fixed diff = A - (A1 + A2 + A3);
	std::cout << diff.getRawBits() << " = " << diff << " < " << tolerance.getRawBits() << " = " << tolerance << std::endl;
	
	if (diff.getRawBits() < 0) {
	    diff = diff * Fixed(-1);
	}

	if (A == 0)
		std::cout << "è un segmento, ma comunque ";
	else
		std::cout << "è un triangolo e ";
	
	if (diff <= tolerance)
	    return true;
	return false;
}