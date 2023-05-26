#include "Base.hpp"

int     main( void )
{
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    std::cout << std::endl;

    std::cout << "a* = "; identify(a);
    std::cout << "a& = "; identify(*a); std::cout << std::endl;

    std::cout << "b* = "; identify(b);
    std::cout << "b& = "; identify(*b); std::cout << std::endl;

    std::cout << "c* = "; identify(c);
    std::cout << "c& = "; identify(*c); std::cout << std::endl;

    std::cout << "d* = "; identify(d);
    std::cout << "d& = "; identify(*d); std::cout << std::endl;

    std::cout << std::endl;


    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}