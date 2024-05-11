/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:28 by marco             #+#    #+#             */
/*   Updated: 2024/05/12 00:29:29 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif