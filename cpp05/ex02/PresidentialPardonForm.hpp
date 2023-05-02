#ifndef __PARDON_H__
# define __PARDON_H__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Form.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;

    protected:
        void    do_execute(Bureaucrat const &) const;

    public:

        PresidentialPardonForm();
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(PresidentialPardonForm const &); 
        PresidentialPardonForm& operator=(PresidentialPardonForm const &);
        ~PresidentialPardonForm();
    
        class PresidentialPardonFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif