#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
						: AForm(target, 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

const char*	RobotomyRequestForm::RobotomyRequestFailedException::what() const throw()
{
	return "Robotomy Exception: Failed to request robotomy.";
}

void    RobotomyRequestForm::do_execute(Bureaucrat const &other) const
{
	
	std::cout << other.getName() << " has been robotomized successfully 50\% of the time\n";
}

// AForm*	clone(std::string const &target) const
// {
// 	return new RobotomyRequestForm(target);
// }