#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src)
	: _result(src._result), _expression(src._expression) {}

RPN::RPN(const char* expression)
{

	_expression = expression;
	_result = calculateExpression();
}

RPN::~RPN() {}

RPN RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		_result = rhs._result;
		_expression = rhs._expression;
	}
	return (*this);
}

int	RPN::doOperation(char operation, int first, int second)
{
	if (operation == '+')
		return first + second;
	else if (operation == '-')
		return first - second;
	else if (operation == '*')
		return first * second;
	else if (operation == '/')
	{
		if (second == 0)
		{	
			_result = 0;
			throw DivisionByZeroException();
		}
		else
			return first / second;
	}
	else
	{
		_result = 0;
		throw WrongOperationException();
	}
}

bool	RPN::isOperator(char ch) const
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}	

int RPN::calculateExpression()
{
	std::stack<int>	numbers;
	int		first_num;
	int		second_num;
	char	ch;

	for (size_t i = 0; i < _expression.size(); i++)
	{
		ch = _expression[i];
		if (ch != ' ')
		{
			if (isOperator(ch))
			{
				if (numbers.size() >= 2)
				{
					second_num = numbers.top();
					numbers.pop();
					first_num = numbers.top();
					numbers.pop();
					_result = doOperation(ch, first_num, second_num);
					numbers.push(_result);
				}
				else
				{
					_result = 0;
					throw InvalidNotationException();
				}
			}
			else
				numbers.push(ch - '0');
		}
	}
	if (numbers.empty() || numbers.size() > 1)
	{
		_result = 0;
		throw InvalidNotationException();
	}
	_result = numbers.top();
	return _result;
}

std::string	RPN::getExpr() const
{
	return _expression;
}

int	RPN::getResult() const
{
	return this->_result;
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Error: division by zero.";
}

const char* RPN::WrongOperationException::what() const throw()
{
	return "Error: invalid operation. It should be one of these: '+-*/'.";
}

const char* RPN::InvalidNotationException::what() const throw()
{
	return "Error: invalid notation.";
}