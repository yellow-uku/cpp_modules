#include "Animal.hpp"

A_Animal::A_Animal()
        : _type("A_Animal")
{
    std::cout << "A_Animal Default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal&other)
{
    this->_type = other._type;
    std::cout << "A_Animal Copy constructor called" << std::endl;

}

A_Animal::~A_Animal()
{
    std::cout << "A_Animal Destructor called" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal &other)
{
    this->_type = other._type;
    std::cout << "A_Animal Copy assignment operator called" << std::endl;
    return *this;
}

void    A_Animal::makeSound() const
{
    std::cout << "A_Animal sound" << std::endl;
}

std::string A_Animal::getType() const
{
    return this->_type;
}