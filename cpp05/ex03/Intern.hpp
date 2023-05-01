#ifndef __INTERN_H__
# define __INTERN_H__

#include "Intern.hpp"
#include "AForm.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        AForm**  arrForms;

    public:
        Intern();
        ~Intern();
    
        AForm*  makeForm(std::string const &, std::string const &) const;

        class FormNotFoundException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif