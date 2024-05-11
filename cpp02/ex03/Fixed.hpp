/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:27:42 by marco             #+#    #+#             */
/*   Updated: 2024/05/12 00:27:43 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int raw_bits;
    static const int bits = 8;

public:
    Fixed();
    Fixed(const Fixed &rhs);
    ~Fixed();
    Fixed &operator=(Fixed const &rhs);

    Fixed(const int raw);
    Fixed(const float raw);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

	bool operator>(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;

	Fixed operator+(const Fixed &obj) const;
	Fixed operator-(const Fixed &obj) const;
	Fixed operator*(const Fixed &obj) const;
	Fixed operator/(const Fixed &obj) const;

	Fixed &operator++(); //prefijo
	Fixed operator++(int); //suffisso
	Fixed &operator--(); //prefisso
	Fixed operator--(int); //suffisso

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif