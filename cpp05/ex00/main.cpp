#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat carl("Carl", 150);
        Bureaucrat bob("Bob", 2);

        // if (bob.getGrade() < 1)
        // {
        //     throw Bureaucrat::GradeTooHighException();
        //     // throw GradeTooHighException("Too high grade. Please, enter valid value.");
        // }

        std::cout << std::endl;
        std::cout << carl << std::endl;
        std::cout << bob << std::endl;
    
        carl.decrementGrade();

        bob.incrementGrade();
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    // catch (Bureaucrat::GradeTooLowException & ex)
    // {
    //     std::cout << ex.what() << std::endl;
    // }
   
    // Bureaucrat b("Carl", 1);
    // Bureaucrat  c(b);
    
    // std::cout << b.getGrade()  << ' ' << c.getGrade() << std::endl;
    // b = c;
    // std::cout << b.getGrade()  << ' ' << c.getGrade()  << std::endl;
    // std::cout << b;
    return 0;
}