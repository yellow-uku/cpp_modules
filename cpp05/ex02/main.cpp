#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat carl("Carl", 2);
        Bureaucrat bob("Bob", 110);
        Form first("Pepega Form", 50, 140);
        Form second("Form from other pepegas", 1, 110);
        
        std::cout << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;

        std::cout << "1st form: " << first.getIsSigned() << std::endl;
        std::cout << "2nd form: " << second.getIsSigned() << std::endl;
        
        first.beSigned(carl);
        second.beSigned(bob);

        std::cout << "1st form: " << first.getIsSigned() << std::endl;
        std::cout << "2nd form: " << second.getIsSigned() << std::endl;

        std::cout << std::endl;
        carl.signForm(first);
        carl.signForm(second);
        bob.signForm(first);

        std::cout << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
        // if (bob.getGrade() < 1)
        // {
        //     throw Bureaucrat::GradeTooHighException();
        //     // throw GradeTooHighException("Too high grade. Please, enter valid value.");
        // }

        // std::cout << std::endl;
        // std::cout << carl << std::endl;
        // std::cout << bob << std::endl;
    
        // carl.decrementGrade();

        // bob.incrementGrade();

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
