#ifndef __INTERN_H__
# define __INTERN_H__

#include "Intern.hpp"
#include "Form.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &);
        Intern &operator=(Intern const &);
        ~Intern();
    
        AForm*  makeForm(std::string const &, std::string const &) const;

        class FormNotFoundException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif