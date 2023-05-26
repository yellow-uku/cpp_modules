#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# ifndef MUTANTSTACK_HPP
#  error MutantStack.tpp should only be included from MutantStack.hpp
# endif

template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "Constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &copy) : MutantStack<T>::stack(copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &copy)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this == &copy)
		return (*this);
	this->c = copy.c;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destructor called" << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end()
{
	return this->c.end();
}

#endif