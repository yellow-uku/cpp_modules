#include "Fixed.hpp"

Fixed::Fixed()
		: _rawBits(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
		: _rawBits(num << _fracBits)
{
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
		: _rawBits(roundf(num * (1 << _fracBits)))
{
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &bits)
{
	_rawBits = bits._rawBits;
//	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{	
	return _rawBits;
}

void Fixed::setRawBits(int bits)
{
//	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = bits;
}

Fixed& Fixed::operator=(const Fixed &bits)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = bits._rawBits;
	return *this;
}

bool Fixed::operator>(Fixed const &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->getRawBits() != other.getRawBits());
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
	return Fixed(this->toFloat() * bits.toFloat());
}

Fixed Fixed::operator/(const Fixed &bits) const
{
	if (bits._rawBits == 0)
	{
		std::cout << "Error: division by zero" << std::endl;
		return Fixed(0.0f);
	}
	return Fixed(this->toFloat() / bits.toFloat());
}


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
	*this += Fixed(EPSILON);
	return *this;
}

// post-increment

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(*this);
	return temp;
}

// pre-decrement

Fixed& Fixed::operator--()
{
	*this = *this - EPSILON;
	return *this;
}

// post-decrement

Fixed Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(*this);
	return temp;
}


const Fixed& Fixed::min(const Fixed &x, const Fixed &y)
{
	if (x < y)
		return x;
	else
		return y;
}

// static member functon min

const Fixed&	min(const Fixed &x, const Fixed &y)
{
	return (Fixed::min(x, y));
}

Fixed&	Fixed::min(Fixed &x, Fixed &y)
{
	if (x < y)
		return x;
	else
		return y;
}

// static member functon min

Fixed&	min(Fixed &x, Fixed &y)
{
	return (Fixed::min(x, y));
}

const Fixed&	Fixed::max(const Fixed &x, const Fixed &y)
{
	if (x < y)
		return y;
	else
		return x;
}

// static member functon max

const Fixed&	max(const Fixed &x, const Fixed &y)
{
	return (Fixed::max(x, y));
}

Fixed&	Fixed::max(Fixed &x, Fixed &y)
{
	if (x < y)
		return y;
	else
		return x;
}

// static member functon max

Fixed&	max(Fixed &x, Fixed &y)
{
	return (Fixed::max(x, y));
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