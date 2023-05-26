#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

const char* NotFoundElementException::what() const throw()
{
    return "Exception: Element not found.";
}

template <typename T>
typename T::iterator easyfind(T& src, int find)
{
    typename T::iterator    it;

    it = std::find(src.begin(), src.end(), find);

    if (it == src.end())
        throw NotFoundElementException();
    return it;
};



#endif