#include "Animal.hpp"

Animal::Animal()
        : _type("Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal&other)
{
    this->_type = other._type;
    std::cout << "Animal Copy constructor called" << std::endl;

}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    this->_type = other._type;
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

void    Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}