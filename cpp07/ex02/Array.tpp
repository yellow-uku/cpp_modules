#ifndef ARRAY_TPP
# define ARRAY_TPP

# ifndef ARRAY_HPP
# error Array.tpp should be included from Array.hpp
# endif

template<typename T>
Array<T>::Array()
{
    std::cout << "Default constructor without parametrs is called" << std::endl;
    _array = NULL;
    _size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << "Default constructor is called" << std::endl;
    _array = new T[n];
    _size = n;
}

template<typename T>
Array<T>::~Array()
{
    std::cout << "Destructor is called" << std::endl;
    if(_array)
            delete[] _array;
}

template<typename T>
Array<T>::Array(Array<T> const &src)
{
	std::cout << "Copy constructor is called" << std::endl;
	this->_array = NULL;
	*this = src;
}

template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &src)
{
	std::cout << "Copy assignment is called" << std::endl;
	if (this == &src)
		return (*this);
	if (this->_array)
		delete [] this->_array;
	this->_array = new T[src._size];
	this->_size = src._size;
	return (*this);
}

template<typename T>
T   &Array<T>::operator[](int const index) const
{
    if (index < 0 || index >= (int)_size)
        throw Array<T>::InvalidIndexArray();
    return(_array[index]);
}

template<typename T>
unsigned int    Array<T>::size() const
{ 
    return (_size);
}

template<typename T>
char const  *Array<T>::InvalidIndexArray::what() const throw()
{
    return ("Invalid index of array!");
}

#endif