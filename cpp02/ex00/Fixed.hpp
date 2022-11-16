#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &);
		Fixed& operator=(const Fixed &);


		int getRawBits(void) const;
		void setRawBits(int const);
};

#endif