#ifndef __PARDON_H__
# define __PARDON_H__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;

    protected:
        void    do_execute(Bureaucrat const &) const;

    public:
        PresidentialPardonForm(std::string);
        ~PresidentialPardonForm();

        // AForm*  clone(std::string const &) const;
    
        class PresidentialPardonFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif