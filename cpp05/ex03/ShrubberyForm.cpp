#include "ShrubberyForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
						: AForm(target + "_shrubbery", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const char*	ShrubberyCreationForm::ShrubberyCreationFailedException::what() const throw()
{
	return "Exception: Failed to create shrubbery.";
}

void    ShrubberyCreationForm::do_execute(Bureaucrat const & executor) const
{
	try
    {
		std::ofstream NewFile(this->_target + "_shrubbery");
		NewFile << "Pepega ASCII Tree" << std::endl;
		NewFile << "\n" \
		"			_-_	\n" \
		"		/~~   	~~\\	\n" \
		"	/~~         	~~\\	\n" \
		"   {                   }	\n" \
		"    \\    _-     -_    /	\n" \
		"		~  \\\\ //  ~	\n" \
		"	_- -   	| | _- _	\n" \
		"		_ - | |   -_	\n" \
		"  		   // \\\\";
		NewFile.close();
	}
	catch (std::exception &ex)
	{
		std::cout << executor.getName() << "can't create shrubs" << '\n';
		throw ShrubberyCreationFailedException();
	}
}