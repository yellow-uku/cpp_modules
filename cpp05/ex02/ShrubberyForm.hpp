#ifndef __SHRUBBERY_H__
# define __SHRUBBERY_H__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:

        std::string _target;

    public:

        ShrubberyCreationForm(const std::string);
        ~ShrubberyCreationForm();

        void    createFile();

        class ShrubberyCreationFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


#endif