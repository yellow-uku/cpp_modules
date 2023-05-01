#include "Intern.hpp"
#include "AForm.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" <<  std::endl;

	AForm*	initial_bufer[3] = {
	new RobotomyRequestForm(""),
	new ShrubberyCreationForm(""),
	new PresidentialPardonForm("")
	};

	// to avoid error with unused bufer in constructor -_-
	arrForms = new AForm*[3];
	for (int i = 0 ; i < 3; i++) {
		arrForms[i] = initial_bufer[i];
	}
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
	for (int i = 0; i < 3; i++) {
		delete arrForms[i];
	}
}

const char*	Intern::FormNotFoundException::what() const throw()
{
	return "Intern Exception: Intern can't find this form.";
}

AForm*  Intern::makeForm(std::string const &name, std::string const &target) const
{
	std::string arrFormNames[3] = {
		"robotomy request form",
		"shrubbery creation form",
		"presidential pardon form"
	};
	
	AForm*	arrForms[3] = {
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target),
		new PresidentialPardonForm(target)
	};
	
	std::cout << '\n';

	AForm*	arrResForm = NULL;	

	for (int i = 0; i < 3; i++)
	{
		if (name == arrFormNames[i])
		{
			std::cout << "Intern creates " << arrForms[i]->getName() << std::endl;
			return arrForms[i];
		}
	}

	if (!arrResForm)
	{
		std::cout << "Intern can't create the form." << std::endl;
		throw Intern::FormNotFoundException();
	}
	return arrResForm;
}