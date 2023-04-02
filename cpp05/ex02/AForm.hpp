#ifndef __A_FORM_H__
# define __A_FORM_H__

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:

        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:

        AForm(const std::string, const int, const int);
        ~AForm();

        const std::string   getName() const = 0;
        bool                getIsSigned() const = 0;
        int                 getGradeToSign() const = 0;
        int                 getGradeToExecute() const = 0;

        void                beSigned(Bureaucrat &);
        
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream &, const AForm &);

#endif
