#include "Form.hpp"

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
    return "Exception: Too high grade.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Exception: Too low grade.";
}

void    Form::beSigned(Bureaucrat &other)
{
    if (this->getGradeToSign() >= other.getGrade())
        this->_isSigned = true;
    else
        this->_isSigned = false;
    return;
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