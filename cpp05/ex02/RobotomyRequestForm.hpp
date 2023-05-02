#ifndef __ROBOTOMY_H__
# define __ROBOTOMY_H__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Form.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    protected:
        void    do_execute(Bureaucrat const &) const;

    public:

        RobotomyRequestForm();
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(RobotomyRequestForm const &); 
        RobotomyRequestForm& operator=(RobotomyRequestForm const &);
        ~RobotomyRequestForm();
    
        class RobotomyRequestFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif