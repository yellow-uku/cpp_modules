#include "Fixed.hpp"

int main()
{
	Fixed a(1);
	Fixed const b(10);
	Fixed const c (42.42f);
	Fixed const d(b);

	Fixed const e(42.5f);
	Fixed const g(1.5f);
	Fixed const f(121);

	Fixed num(1.3f);
//	a = g - e;
	a = num++;

//	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "num is " << num << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "f is " << f << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}