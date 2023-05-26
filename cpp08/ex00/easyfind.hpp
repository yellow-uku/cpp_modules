#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T&, int);

class NotFoundElementException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif