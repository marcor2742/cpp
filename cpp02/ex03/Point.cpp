/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:27:25 by marco             #+#    #+#             */
/*   Updated: 2024/05/12 00:27:26 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &rhs) : x(rhs.x), y(rhs.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &rhs)
{
	std::cout << "do not use copy constructor on a Point obj, because attributes are const" << std::endl;
	if (this != &rhs)
	{
		const_cast<Fixed&>(x) = rhs.x;
		const_cast<Fixed&>(y) = rhs.y;
	}
	return *this;
}

const Fixed &Point::getX() const
{
	return this->x;
}

const Fixed &Point::getY() const
{
	return this->y;
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}