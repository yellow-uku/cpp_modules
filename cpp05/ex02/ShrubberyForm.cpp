#include "ShrubberyForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("NoTarget")
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
						: AForm(target + "_shrubbery", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) 
    : AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return *this;
}

const char*	ShrubberyCreationForm::ShrubberyCreationFailedException::what() const throw()
{
	return "Shrubbery Exception: Failed to create shrubbery.";
}

const char*	ShrubberyCreationForm::ShrubberyOpenFileException::what() const throw()
{
	return ("Shrubbery Exception: File can't be opened.");
}

void    ShrubberyCreationForm::do_execute(Bureaucrat const & executor) const
{
	try
    {
		std::ofstream newFile(this->_target + "_shrubbery");
		if (!newFile.is_open())
			throw ShrubberyCreationForm::ShrubberyOpenFileException();

		newFile << "Pepega ASCII Tree" << std::endl;
		newFile << "\n" \
		"			_-_	\n" \
		"		/~~   	~~\\	\n" \
		"	/~~         	~~\\	\n" \
		"   {                   }	\n" \
		"    \\    _-     -_    /	\n" \
		"		~  \\\\ //  ~	\n" \
		"	_- -   	| | _- _	\n" \
		"		_ - | |   -_	\n" \
		"  		   // \\\\";
		newFile.close();
	}
	catch (std::exception &ex)
	{
		std::cout << executor.getName() << " can't create shrubs" << '\n';
		throw ShrubberyCreationFailedException();
	}
}