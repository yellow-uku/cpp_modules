#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target, int sign, int exec)
						: _target(target), _sign(sign), _exec(exec)
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
	if ((_sign != 72) || (_exec != 45))
		throw RobotomyRequestFailedException();
}

RobotomyRequestForm::~RobotomyRequestForm(){}

const char*	RobotomyRequestForm::RobotomyRequestFailedException::what() const throw()
{
	return "Exception: Failed to request robotomy.";
}


