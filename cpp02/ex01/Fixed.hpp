#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_rawBits; 
		static const int	_fracBits = 8;

	public:
		Fixed();
		Fixed(const int);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &);
		Fixed& operator=(const Fixed &);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits( void ) const;
		void setRawBits(int bits);
};

std::ostream & operator<<(std::ostream &, const Fixed &);

#endif