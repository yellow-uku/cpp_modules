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

    protected:
        void    do_execute(Bureaucrat const &) const;
    public:

        ShrubberyCreationForm(const std::string);
        ~ShrubberyCreationForm();

        class ShrubberyCreationFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


#endif