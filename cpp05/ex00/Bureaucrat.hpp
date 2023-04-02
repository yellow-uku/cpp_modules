#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(const std::string, int);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);

		Bureaucrat& operator=(const Bureaucrat &);
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				// GradeTooHighException(const char* msg) : std::exception(msg){};
				virtual const char* what() const throw()
				{
					return "Exception: Too high grade.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				// GradeTooLowException(const char* msg) : std::exception(msg){};
				virtual const char* what() const throw()
				{
					return "Exception: Too low grade.";
				}
		};		
};

std::ostream& operator << (std::ostream &, const Bureaucrat &);

#endif