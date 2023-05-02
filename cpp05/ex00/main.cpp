#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat carl("Carl", 150);
        Bureaucrat bob("Bob", 2);

        std::cout << '\n';
    
        bob.incrementGrade();
        std::cout << bob << std::endl;

        carl.decrementGrade();
        std::cout << carl << std::endl;
        
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
}