#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat carl("Carl", 2);
        Bureaucrat bob("Bob", 150);
        Form first("Pepega Form", 50, 140);
        Form second("Another Pepega Form", 51, 141);

        std::cout << std::endl;
        std::cout << std::boolalpha << first << std::endl;
        carl.signForm(first);
        std::cout << std::boolalpha << first << std::endl;
        bob.signForm(first);
        std::cout << std::boolalpha << first << std::endl;
        
        std::cout << std::endl;
        std::cout << "2nd form: " << second.getIsSigned() << std::endl;
        carl.signForm(second);
        // second.beSigned(carl);
        std::cout << "2nd form: " << second.getIsSigned() << std::endl;
        // std::cout << std::endl;
        // std::cout << first << std::endl;
        // std::cout << second << std::endl;

        // std::cout << "1st form: " << first.getIsSigned() << std::endl;
        // std::cout << "2nd form: " << second.getIsSigned() << std::endl;
        
        
        // second.beSigned(bob);

        // std::cout << "1st form: " << first.getIsSigned() << std::endl;
        // std::cout << "2nd form: " << second.getIsSigned() << std::endl;

        // carl.signForm(second);
        // bob.signForm(first);

        // std::cout << std::endl;
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
