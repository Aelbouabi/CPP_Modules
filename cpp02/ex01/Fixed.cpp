#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy Assigment Operator called" << std::endl;
	if(this != &src)
		this->value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const b)
{
	this->value = b;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << bits;
}

Fixed::Fixed(float const nf)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(nf * (1 << bits));
}

std::ostream  &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return out;
}

float   Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << bits));
}

int   Fixed::toInt( void ) const
{
	return (this->value >> bits);
}