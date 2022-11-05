#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>
#include <cmath>

# define EPSILON 0.016304f

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

	// Comparison Operators

		Fixed&	operator=(const Fixed &);
		Fixed	operator+(const Fixed &) const;
		Fixed	operator-(const Fixed &) const;
		Fixed	operator*(const Fixed &) const;


		Fixed&	operator+=(const Fixed &);
		Fixed&	operator-=(const Fixed &);
		Fixed&	operator++();  // pre-increment incrementing
		Fixed&	operator++(int); // post-increment incrementing (?)
		Fixed&	operator--();  // pre-increment decrementing
		Fixed&	operator--(int); // post-increment decrementing (?)

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits( void ) const;
		void	setRawBits(int bits);
};

std::ostream & operator<<(std::ostream &, const Fixed &);

#endif