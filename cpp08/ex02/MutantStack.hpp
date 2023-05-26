#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		MutantStack();
		MutantStack (MutantStack<T> const &);
		MutantStack<T>  &operator=(MutantStack<T> const &);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin();
		iterator	end();
};

# include "MutantStack.tpp"

#endif