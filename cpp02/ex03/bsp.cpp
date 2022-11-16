#include "Fixed.hpp"
#include "Point.hpp"

bool is_on_the_right(Point const a, Point const b, Point const c)
{

	Point new_a = Point();
	Point new_b = b - a;
	Point new_c = c - a;
	Point normal = new_b.normal();
	float dot = normal.dot(new_c);

//	std::cout << "Dot product is " << dot << std::endl;

	return dot > 0;
}

bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	if ( is_on_the_right(a, b, point)
					&& is_on_the_right(b, c, point)
					&& is_on_the_right(c, a, point)){
			return true;
	}
	return false;
}