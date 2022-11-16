#include "Fixed.hpp"

Fixed::Fixed() 
		: _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &bits)
{
	setRawBits(bits._rawBits);
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const bits)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = bits;
}

Fixed& Fixed::operator=(const Fixed &bits)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = bits._rawBits;
	return *this;
}