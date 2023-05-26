#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	private:
		std::vector<int>    _intVector;
		unsigned int        _size;

	public:
		Span();
		Span(unsigned int);
		Span(Span const &);
		Span    &operator=(Span const &);
		~Span();

		void    		addNumber(int);
		void			addNumbersRange(std::vector<int>::iterator begin,
										std::vector<int>::iterator end, int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
		void			printVector();

		typedef std::vector<int>::iterator iterator;

		std::vector<int>::iterator	begin();
		std::vector<int>::iterator	end();

	class WrongLengthException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class ArrayOverflowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif