#include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
		: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm Constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

std::ostream& operator << (std::ostream & out, const AForm &other)
{
	out << "Name of the AForm: " << other.getName() << std::endl;
	out << "Is it signed or not: " << other.getIsSigned() << std::endl;
	out << "Grade to sign: " << other.getGradeToSign() << std::endl;
	out << "Grade to execute: " << other.getGradeToExecute() << std::endl;
	return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form Exception: Too high grade.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form Exception: Too low grade.";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form Exception: The form is not signed.";
}

void    AForm::beSigned(Bureaucrat &other)
{
	if (this->getGradeToSign() >= other.getGrade())
		this->_isSigned = true;
	else
		this->_isSigned = false;
	return;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	
	this->do_execute(executor);
}

const std::string   AForm::getName() const
{
	return this->_name;
}

bool                AForm::getIsSigned() const
{
	return this->_isSigned;
}

int           AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int           AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}