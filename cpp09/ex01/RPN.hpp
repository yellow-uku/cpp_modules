#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		int			_result;
		std::string	_expression;

	public:

		RPN();
		RPN(const char* expression);
		RPN(const RPN &src);
		~RPN();

		RPN operator=(const RPN &rhs);

		int			calculateExpression();
		bool		isOperator(char) const;
		int			doOperation(char operation, int num1, int num2);

		std::string	getExpr() const;
		int			getResult() const;

		class DivisionByZeroException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class WrongOperationException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidNotationException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
}; 


#endif