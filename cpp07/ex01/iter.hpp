#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void    iter(T* arr, size_t arr_size, void (*fun)(T&))
{
    for (size_t i = 0; i < arr_size; i++)
        (*fun)(arr[i]);
}

template<typename T>
void    print_arr(T* arr, size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
        std::cout << arr[i] << " ";
    std::cout << arr[len - 1];
}

template<typename T>
void    ft_power(T& num)
{
    num *= num;
}

#endif