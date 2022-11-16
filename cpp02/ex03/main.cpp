#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0.0,0.0);
	Point b(1.0,0.0);
	Point c(0.0,1.0);
	Point d(0.1,0.1);

	std::cout << "Is a point in triangle? " << bsp(a, b, c, d) << std::endl;

	Point new_d(-0.1,0.1);
	std::cout << "Is a new point in triangle? " << bsp(a, b, c, new_d) << std::endl;
	return 0;
}