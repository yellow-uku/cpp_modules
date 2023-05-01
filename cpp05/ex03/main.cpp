#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat carl("Carl", 2);

	Intern pepega;

	std::cout << '\n';

	AForm*	ppf = pepega.makeForm("presidential pardon form", "Pardon");
	AForm*	scf = pepega.makeForm("shrubbery creation form", "Shrubbery");
	AForm*	rrf = pepega.makeForm("robotomy request form", "Robotomy");

	// test failed form
	std::cout << '\n';
	try
	{
		AForm*	failedForm = pepega.makeForm("Whatever form", "New");
		carl.executeForm(*failedForm);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
	// test if form is signed or not
	std::cout << '\n';
	try
	{
		carl.executeForm(*rrf);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
	// sign and execute created form
	std::cout << '\n';
	try
	{
		carl.signForm(*rrf);
		carl.executeForm(*rrf);

		carl.signForm(*scf);
		carl.executeForm(*scf);

		carl.signForm(*ppf);
		carl.executeForm(*ppf);
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << '\n';
 
//	deleteData(&form); // I will do it iinn desctructor stead
//	with new member attribute: array of pointers to forms

	return 0;
}

