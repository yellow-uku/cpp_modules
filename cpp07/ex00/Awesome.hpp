#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>

class Awesome
{
    private:
        int _n;
    
    public:
        Awesome(): _n(0) {}
	    Awesome(int n) : _n(n) {}
	    Awesome	&operator=(Awesome &a) {_n = a._n; return *this;}
	    bool	operator==(Awesome const &rhs) const {return (this->_n == rhs._n);}
	    bool	operator!=(Awesome const &rhs) const {return (this->_n != rhs._n);}
	    bool	operator>(Awesome const &rhs) const {return (this->_n > rhs._n);}
	    bool	operator<(Awesome const &rhs) const {return (this->_n < rhs._n);}
	    bool	operator>=(Awesome const &rhs) const {return (this->_n >= rhs._n);}
	    bool	operator<=(Awesome const &rhs) const {return (this->_n <= rhs._n);}
	    int		get_n() const {return (_n);}

};

std::ostream	&operator<<(std::ostream &o, const Awesome &a) {o << a.get_n(); return (o);}


#endif