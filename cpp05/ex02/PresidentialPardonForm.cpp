#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Creation Form", 25, 5), _target("NoTarget")
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
} 

PresidentialPardonForm::PresidentialPardonForm(std::string target)
						: AForm(target, 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) 
    : AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return *this;
}

const char*	PresidentialPardonForm::PresidentialPardonFailedException::what() const throw()
{
	return "PresidentialPardon Exception: Failed to request robotomy.";
}

void    PresidentialPardonForm::do_execute(Bureaucrat const &other) const
{
	
	std::cout << other.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

