#include "Form.hpp"

Form::Form() 
    : _name("NoName"), _isSigned(false), _gradeToSign(42), _gradeToExecute(42)
{
    std::cout << "Form Default Constructor called" << std::endl;
} 

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
        : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form Constructor called" << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &copy)
    : _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
    std::cout << "Form Copy constructor called" << std::endl;
    
    if(_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (_gradeToSign >150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
    if (this != &copy)
        *this = copy;
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

std::ostream& operator << (std::ostream & out, const Form &other)
{
    out << "Name of the Form: " << other.getName() << std::endl;
    out << "Is it signed or not: " << other.getIsSigned() << std::endl;
    out << "Grade to sign: " << other.getGradeToSign() << std::endl;
    out << "Grade to execute: " << other.getGradeToExecute() << std::endl;
    return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Exception: Too high grade.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Exception: Too low grade.";
}

const char* Form::AlreadySignedException::what() const throw()
{
    return "Form Exception: The form is already signed.";
}

void    Form::beSigned(Bureaucrat &other)
{
    if (_isSigned)
        throw Form::AlreadySignedException();

    if (this->getGradeToSign() >= other.getGrade())
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const std::string   Form::getName() const
{
    return this->_name;
}

bool                Form::getIsSigned() const
{
    return this->_isSigned;
}

int           Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int           Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}