#include "WrongCat.hpp"

WrongCat::WrongCat()
    : _type("WrongCat")
{
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat&other)
{
    this->_type = other._type;
    std::cout << "WrongCat Copy constructor called" << std::endl;

}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    this->_type = other._type;
    return *this;
}

std::string WrongCat::getType() const
{
    return this->_type;
}

void    WrongCat::makeSound() const
{
    std::cout << "Wrong Meow Meow" << std::endl;
}