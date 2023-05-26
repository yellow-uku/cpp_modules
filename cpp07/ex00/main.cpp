#include "whatever.hpp"
#include "Awesome.hpp"

int main()
{
	std::cout << "----------------INTS----------------\n\n";

	int a = 5;
	int b = 10;

	::swap(a, b);
	std::cout << "a = " << a << " | b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << '\n';

	std::cout << "----------------STRINGS----------------\n\n";

	std::string c = "it's wednesday";
	std::string d = "my dudes";
	
	::swap(c, d);
	std::cout << "c = " << c << " | d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << '\n';

	std::cout << "----------------FLOATS----------------\n\n";

	float	z = 42.42f;
	float	w = 21.21f;

	::swap(z, w);
	std::cout << "z = " << z << " | w = " << w << std::endl;
	std::cout << "min(z, w) = " << ::min(z, w) << std::endl;
	std::cout << "max(z, w) = " << ::max(z, w) << std::endl;

	std::cout << "----------------CLASS----------------\n\n";

	Awesome	me(10);
	Awesome	you(20);

	::swap(me, you);
	std::cout << "me = " << me << " | you = " << you << std::endl;
	std::cout << "min(me, you) = " << ::min(me, you) << std::endl;
	std::cout << "max(me, you) = " << ::max(me, you) << std::endl;

	return 0;
}