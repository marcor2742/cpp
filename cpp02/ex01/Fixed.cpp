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
	std::cout << "Copy assignment operator called" << std::endl;
    this->raw_bits = rhs.raw_bits;
    return *this;
}

Fixed::Fixed(const int raw) : raw_bits(raw << bits)
{
    std::cout << "constructor const int called" << std::endl;
}

Fixed::Fixed(const float raw)
{
    std::cout << "constructor const float called" << std::endl;
    this->raw_bits = roundf(raw * (1 << bits)); // raw * 2^bits, (non raw << bits perche' e' un float)
}

int Fixed::getRawBits( void ) const
{
    return this->raw_bits;
}

void Fixed::setRawBits( int const raw )
{
	this->raw_bits = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)raw_bits / (float)(1 << bits);
}

int Fixed::toInt( void ) const
{
	return raw_bits / (1 << bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	return o << i.toFloat();
}
