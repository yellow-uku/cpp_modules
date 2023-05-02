#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("NoTarget")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
} 

RobotomyRequestForm::RobotomyRequestForm(std::string target)
						: AForm(target, 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) 
    : AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return *this;
}

const char*	RobotomyRequestForm::RobotomyRequestFailedException::what() const throw()
{
	return "Robotomy Exception: Failed to request robotomy.";
}

void    RobotomyRequestForm::do_execute(Bureaucrat const &other) const
{
	
	std::cout << other.getName() << " has been robotomized successfully 50\% of the time\n";
}