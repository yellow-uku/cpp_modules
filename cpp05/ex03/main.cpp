#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	freeData(AForm **form)
{
	if (*form)
	{
		delete *form;
		*form = NULL;
	}
}

int main()
{
	Bureaucrat carl("Carl", 2);
	// AForm*	ppf;
	AForm*	scf;
	// AForm*	rrf;

	Intern pepega;

	std::cout << '\n';

	// ppf = pepega.makeForm("presidential pardon form", "Pardon");
	scf = pepega.makeForm("shrubbery creation form", "Shrubbery");
	// rrf = pepega.makeForm("robotomy request form", "Robotomy");

	// test failed form
	// std::cout << '\n';
	// try
	// {
	// 	AForm*	failedForm = pepega.makeForm("Whatever form", "New");
	// 	carl.executeForm(*failedForm);
	// }
	// catch(const std::exception& ex)
	// {
	// 	std::cout << ex.what() << '\n';
	// }

	// test if form is signed or not
	std::cout << '\n';
	try
	{
		carl.executeForm(*scf);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}

	// sign and execute created form
	std::cout << '\n';
	try
	{
		// carl.signForm(*rrf);
		// carl.executeForm(*rrf);

		// carl.signForm(*scf);
		// carl.executeForm(*scf);

		carl.signForm(*scf);
		carl.executeForm(*scf);
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << '\n';
 
	freeData(&scf);
	// freeData(&ppf);
	// freeData(&rrf);

	// system("leaks bureaucrat");

	return 0;
}