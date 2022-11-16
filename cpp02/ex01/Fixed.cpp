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
	setRawBits(bits._rawBits);
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
	setRawBits(bits._rawBits);
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