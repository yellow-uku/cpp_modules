#ifndef __POINT_H__
# define __POINT_H__

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float &, const float &);
		~Point();
		Point(const Point&);

		Point&  operator=(const Point &);
		Point   operator-(Point const &rhs) const;

		Point   normal() const;
		float   dot(Point const &) const;
	};

bool is_on_the_right(Point const, Point const, Point const);
bool bsp(Point const, Point const, Point const, Point const);

#endif