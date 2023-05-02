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

	protected:
		virtual void	do_execute(Bureaucrat const &) const = 0;
	public:

		AForm(const std::string, const int, const int);
		virtual ~AForm();

		const std::string   getName() const;
		bool                getIsSigned() const;
		int                 getGradeToSign() const;
		int                 getGradeToExecute() const;

		void                beSigned(Bureaucrat &);
		void				execute(Bureaucrat const &) const;

		// virtual AForm*		clone(std::string const &) const = 0;
		
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

		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream &, const AForm &);

#endif
