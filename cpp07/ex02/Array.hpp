#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array {

    private:
        unsigned int    _size;
        T               *_array;

    public:
        Array();
        Array(unsigned int n);
        Array(Array<T> const &copy);
        Array<T>    &operator=(Array<T> const &copy);
        ~Array();

        T   &operator[](int const index) const;
        unsigned int size() const;

        class   InvalidIndexArray : public std::exception
        {
            virtual char const *what() const throw();
        };
};

# include "Array.tpp"

#endif