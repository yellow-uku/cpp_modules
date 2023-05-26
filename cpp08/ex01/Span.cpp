#include "Span.hpp"

Span::Span()
{
	std::cout << "Default constructor without parameters is called" << std::endl;
	_size = 0;
	_intVector = std::vector<int>();
}

Span::Span(unsigned int N)
{
	std::cout << "Default constructor is called" << std::endl;
	_size = 0;
	_intVector = std::vector<int>(N);
}

Span::Span(Span const &copy)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

Span    &Span::operator=(Span const &copy)
{
	std::cout << "Copy assignment is called" << std::endl;
	if (this == &copy)
		return (*this);
	_size = copy._size;
	_intVector = copy._intVector;
	return (*this);
}

Span::~Span() { std::cout << "Destructor is called\n\n"; }

void	Span::addNumber(int num)
{
	if (_intVector.size() == _size)
		throw ArrayOverflowException();
	_intVector[_size] = num; 
	++_size;
}

void	Span::addNumbersRange(std::vector<int>::iterator begin,
						std::vector<int>::iterator end, int num)
{
	// std::cout << "here" << '\n';
	if (begin < _intVector.begin() || end > _intVector.end())
		throw std::length_error("Exceeded array length");
	// std::cout << "here" << '\n';
	for (std::vector<int>::iterator it = begin; it != end; ++it)
	{
		*it = num;
		++_size;
		// _intVector.push_back(num);
	}
	
}

unsigned int	Span::shortestSpan()
{
	if (_intVector.size() < 2)
		throw WrongLengthException();

	std::vector<int>	tmp;
	tmp = _intVector;

	std::sort(tmp.begin(), tmp.end());
	unsigned int min_dist = tmp[1] - tmp[0];

	for (size_t i = 2; i < tmp.size(); i++)
	{
		unsigned int	cur_dist = (unsigned int)(tmp[i] - tmp[i - 1]);
		if (cur_dist < min_dist)
			min_dist = tmp[i] - tmp[i - 1];
	}
	return min_dist;
}

unsigned int	Span::longestSpan()
{

	if (_intVector.size() < 2)
		throw WrongLengthException();

	std::vector<int>	tmp;
	tmp = _intVector;

	std::sort(tmp.begin(), tmp.end());
	unsigned int	res = *(tmp.end() - 1) - *tmp.begin();
	
	return res;
}

void	Span::printVector()
{
	std::cout << "Int Vector:\n";
	
	for (std::vector<int>::iterator it = _intVector.begin(); it != _intVector.end(); it++)
	{
		if (it == _intVector.end() - 1)
			std::cout << *it << '\n';
		else
			std::cout << *it << " ";
	}
}

std::vector<int>::iterator Span::begin() { return _intVector.begin(); }
std::vector<int>::iterator Span::end() { return _intVector.end(); }

const char* Span::WrongLengthException::what() const throw()
{
	return "Size of array less than 2.";
}

const char* Span::ArrayOverflowException::what() const throw()
{
	return "Array is already full.";
}