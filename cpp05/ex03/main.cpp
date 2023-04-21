#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bob("Bob", 2);
	Bureaucrat carl("Carl", 147);

	ShrubberyCreationForm shrubbery("first");
	RobotomyRequestForm robotomy("robotomy");
	PresidentialPardonForm	pardon("pardon");

	std::cout << '\n';
	try
	{
		bob.executeForm(shrubbery);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		bob.signForm(robotomy);
		carl.executeForm(robotomy);
		bob.executeForm(robotomy);
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << '\n';
	try
	{
		bob.signForm(pardon);
		bob.executeForm(pardon);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
	
	std::cout << '\n';
	return 0;
}

