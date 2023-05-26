#include "Base.hpp"

Base::~Base() {}

Base*   generate()
{
    Base*	base;
	A*		a_class;
	B*		b_class;
	C*		c_class;
	int		randVal;
    
    randVal = rand() % 10;

    if (randVal >= 0 && randVal <= 3) {
        a_class = new A();
		base = dynamic_cast<Base *>(a_class);
        std::cout << "Randomly class A was created" << std::endl;
    } else if (randVal >= 4 && randVal <= 6) {
        b_class = new B();
		base = dynamic_cast<Base *>(b_class);
        std::cout << "Randomly class B was created" << std::endl;
    } else {
        c_class = new C();
		base = dynamic_cast<Base *>(c_class);
        std::cout << "Randomly class C was created" << std::endl;
    }
    return (base);
}

void    identify(Base *p)
{
    std::cout << "Identify PTR: ";
    if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
	return ;

}

void	identify(Base& p)
{
	std::cout << "Identyfy REF: ";
	try
	{
		Base&	a_class = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a_class;
	}
	catch(std::exception &e)
	{
		try
		{
			Base&	b_class = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b_class;
		}
		catch(std::exception &e)
		{
			try
			{
				Base&	c_class = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c_class;
			}
			catch(std::exception &e)
			{
				std::cout << "unknown" << std::endl;
			}
		}
	}
	return ;
}