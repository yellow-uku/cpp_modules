#include "ShrubberyForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _target(target)
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void    ShrubberyForm::createFile()
{
    fileName = this->_target + "_shrubbery";
    ofstream NewFile(fileName);
    
}