#ifndef __SHRUBBERY_H__
# define __SHRUBBERY_H__

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class ShrubberyCreationForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string);
        ~ShrubberyCreationForm();

        void    createFile();
};


#endif