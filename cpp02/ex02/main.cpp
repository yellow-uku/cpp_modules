#include "Fixed.hpp"

int main()
{
	Fixed a(1);
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	Fixed const e(42.5f);
	Fixed const g(1.5f);
	Fixed const f(120);

	Fixed num(1.3f);

	std::cout << "--------------------------------" << std::endl;
	std::cout << (b > c) << std::endl;
	std::cout << (e < f) << std::endl;
	std::cout << (b >= 10) << std::endl;
	std::cout << (f <= 121) << std::endl;
	std::cout << (b == 10) << std::endl;
	std::cout << (e != f) << std::endl;

	std::cout << "--------------------------------" << std::endl;

	std::cout << (b + c) << std::endl;
	std::cout << (b - c) << std::endl;
	std::cout << (b * c) << std::endl;
	std::cout << (f / b) << std::endl;

	std::cout << "--------------------------------" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	Fixed new_a(2);
	std::cout << new_a << std::endl;
	std::cout << --new_a << std::endl;
	std::cout << new_a << std::endl;
	std::cout << new_a-- << std::endl;
	std::cout << new_a << std::endl;

	std::cout << "--------------------------------" << std::endl;

	Fixed const	t( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << t << std::endl;

	std::cout << "--------------------------------" << std::endl;

	std::cout << Fixed::max(b, t) << std::endl;
	std::cout << Fixed::min(b, t) << std::endl;
	return 0;
}