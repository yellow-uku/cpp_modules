#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>
#include <cmath>

# define EPSILON 0.00390625f

class Fixed
{
	private:
		int					_rawBits; 
		static const int	_fracBits = 8;

	public:
	// Canonical Form
		Fixed();
		Fixed(const int);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &);
	
	// Overloading Operators

		Fixed&	operator=(const Fixed &);

	// Comparison Operators

		bool	operator>(Fixed const &) const;
		bool	operator<(Fixed const &) const;
		bool	operator>=(Fixed const &) const;
		bool	operator<=(Fixed const &) const;
		bool	operator!=(Fixed const &) const;
		bool	operator==(Fixed const &) const;

	// Arithmetic operators

		Fixed	operator+(const Fixed &) const;
		Fixed	operator-(const Fixed &) const;
		Fixed	operator*(const Fixed &) const;
		Fixed	operator/(const Fixed &) const;

		Fixed&	operator+=(const Fixed &);
		Fixed&	operator-=(const Fixed &);
		Fixed&	operator++();  // pre-increment
		Fixed	operator++(int); // post-increment
		Fixed&	operator--();  // pre-decrement
		Fixed	operator--(int); // post-decrement

		static const Fixed&	min(const Fixed &, const Fixed &);
		static Fixed&		min(Fixed &, Fixed &);
		static const Fixed&	max(const Fixed &, const Fixed &);
		static Fixed&		max(Fixed &, Fixed &);
		
		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits( void ) const;
		void	setRawBits(int bits);
};

std::ostream & operator<<(std::ostream &, const Fixed &);

#endif