#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
			: _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	this->_grade = other.getGrade();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy Assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return *this;
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade ";
	out << other.getGrade() << "." << std::endl;
	return out;
}

const char*	 Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Too high grade. Please, enter valid value.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low";
}

const char* Bureaucrat::ExecutuionFailedException::what() const throw()
{
	return "Bureaucrat Exception: Execution failed";
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int		Bureaucrat::getGrade() const
{
    return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &other)
{
	try
	{
		other.beSigned(*this);	// current bureaucrat try to sign the form
		std::cout << this->getName() << " signed " << other.getName() << std::endl;
	}
	catch(const std::exception &ex)
	{	std::cout << this->getName() << " couldn't sign " << other.getName() << std::endl;
	 	std::cout << " because " << ex.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << '\n';
	}
	catch (std::exception & ex)
	{
		std::cout << this->getName() << " failed to execute " << form.getName() << ":\n" << ex.what() << std::endl;
		throw Bureaucrat::ExecutuionFailedException();
	}
}