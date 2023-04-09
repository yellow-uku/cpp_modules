#ifndef __ROBOTOMY_H__
# define __ROBOTOMY_H__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "AForm.hpp"

class RobotomyRequestForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string, int, int);
        ~RobotomyRequestForm();
    
        class RobotomyRequestFailedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif