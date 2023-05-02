#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:
		
		Bureaucrat();
		Bureaucrat(const std::string, int);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);

		Bureaucrat& operator=(const Bureaucrat &);
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void                signForm(Form &);

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};	
};

std::ostream& operator << (std::ostream &, const Bureaucrat &);

#endif