#include "Fixed.hpp"

Fixed::Fixed()
		: _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
		: _rawBits(num << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
		: _rawBits(roundf(num * (1 << _fracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &bits)
{
	_rawBits = bits._rawBits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{	
	return _rawBits;
}

void Fixed::setRawBits(int bits)
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



Fixed Fixed::operator+(const Fixed &bits) const
{
	Fixed new_num;

	new_num._rawBits = this->_rawBits + bits._rawBits;
	return new_num;
}


Fixed Fixed::operator-(const Fixed &bits) const
{
	Fixed new_num;

	new_num._rawBits = this->_rawBits - bits._rawBits;
	return new_num;
}

Fixed Fixed::operator*(const Fixed &bits) const
{
	Fixed new_num;

	new_num._rawBits = this->_rawBits * bits._rawBits;
	return new_num;
}

/*
Fixed Fixed::operator/(const Fixed &bits) const
{
	Fixed new_num;

	if bits == Fixed(0);
	return new_num;
}
*/

Fixed& Fixed::operator-=(const Fixed &bits)
{
	*this = *this - bits;
	return *this;
}

Fixed& Fixed::operator+=(const Fixed &bits)
{
	*this = *this + bits;
	return *this;
}

// pre-increment incrementing

Fixed& Fixed::operator++()
{
	*this += EPSILON;
	return *this;
}

// post-increment incrementing

Fixed& Fixed::operator++(int)
{
	*this += EPSILON;
	return *this;
}

// pre-increment decrementing

Fixed& Fixed::operator--()
{
	*this = *this - EPSILON;
	return *this;
}

// post-increment decrementing

Fixed& Fixed::operator--(int)
{
	*this = *this - EPSILON;
	return *this;
}

float Fixed::toFloat(void) const
{
	return ((float)(_rawBits)) / (1 << _fracBits);
}

std::ostream & operator<<(std::ostream & o, const Fixed &bits)
{
//	std::cout << "Insertion operator called" << std::endl;
	o << bits.toFloat();
	return o;
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> _fracBits);
}