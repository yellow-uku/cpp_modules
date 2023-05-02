#ifndef __SHRUBBERY_H__
# define __SHRUBBERY_H__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm: public AForm
{
    private:

        std::string _target;

    protected:
        void    do_execute(Bureaucrat const &) const;
    public:

        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string);
        ShrubberyCreationForm(ShrubberyCreationForm const &); 
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &);
        ~ShrubberyCreationForm();

        class ShrubberyCreationFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class ShrubberyOpenFileException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


#endif