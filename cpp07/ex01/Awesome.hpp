#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>

class Awesome
{
    private:
        int	_n;
    public:
        Awesome(): _n(42) {}

	int get() const {return (this->_n);}
};

std::ostream	&operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get(); return (o);}

template<typename T>
void    ft_print(T& x)
{
    std::cout << x << std::endl;
}

#endif