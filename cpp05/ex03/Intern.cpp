#include "Intern.hpp"
#include "Form.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" <<  std::endl;
}

Intern::Intern(Intern const &copy)
{
    (void)copy;
    return;
}

Intern  &Intern::operator=(Intern const &copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
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

	AForm*	arrResForm = NULL;	

	for (int i = 0; i < 3; i++)
	{
		// deallocate unused forms
		if (name != arrFormNames[i])
			delete arrForms[i];
		else
		{
			std::cout << "Intern creates " << arrForms[i]->getName() << std::endl;
			arrResForm = arrForms[i];
		}
	}

	if (!arrResForm)
	{
		std::cout << "Intern can't create the form." << std::endl;
		throw Intern::FormNotFoundException();
	}
	return arrResForm;
}