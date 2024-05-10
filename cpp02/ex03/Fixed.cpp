#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0) 
{
}

Fixed::Fixed(const Fixed &rhs)
{
    *this = rhs;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->raw_bits = rhs.raw_bits;
    return *this;
}

Fixed::Fixed(const int raw) : raw_bits(raw << bits)
{
}

Fixed::Fixed(const float raw)
{
    this->raw_bits = roundf(raw * (1 << bits));
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

bool Fixed::operator>(const Fixed &obj) const
{
    return this->raw_bits > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
    return this->raw_bits < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return this->raw_bits >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return this->raw_bits <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
    return this->raw_bits == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return this->raw_bits != obj.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	result.raw_bits = this->raw_bits + obj.getRawBits();
    return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    Fixed result;
	result.raw_bits = this->raw_bits - obj.getRawBits();
    return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    Fixed result;
    result.setRawBits((long long)this->getRawBits() * obj.getRawBits() / (1 << Fixed::bits)); //rimuovo 8 bit perchè ((fixed << 8) * (fixed << 8)) >> 8
    return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    Fixed result;
    result.setRawBits(((long long)this->getRawBits() << Fixed::bits) / obj.getRawBits());      // ( (float * (1 << 8)) / (fixed * (1 << 8)) ) * (1 << 8) (va shiftato il dividendo sennò 1 / 100000000000000 = 0)
    return result;
}

Fixed &Fixed::operator++()
{
	this->raw_bits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->raw_bits++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->raw_bits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->raw_bits--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else return b;	
}
