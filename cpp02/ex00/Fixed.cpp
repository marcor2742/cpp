/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:22 by marco             #+#    #+#             */
/*   Updated: 2024/05/12 00:29:23 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0) 
{
    std::cout << "constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->raw_bits = rhs.raw_bits;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return this->raw_bits;
}

void Fixed::setRawBits( int const raw )
{
    this->raw_bits = raw;
}

