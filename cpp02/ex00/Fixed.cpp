#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed &rhs)
{
    *this = rhs;
}

Fixed::~Fixed(){}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->value = rhs.value;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return this->value;
}

void Fixed::setRawBits( int const raw )
{

}

