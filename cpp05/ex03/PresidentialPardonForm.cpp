#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
						: AForm(target, 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

const char*	PresidentialPardonForm::PresidentialPardonFailedException::what() const throw()
{
	return "PresidentialPardon Exception: Failed to request robotomy.";
}

void    PresidentialPardonForm::do_execute(Bureaucrat const &other) const
{
	
	std::cout << other.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

// AForm*	clone(std::string const &target) const
// {
// 	return new PresidentialPardonForm(target);
// }