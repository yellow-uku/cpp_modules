#include "Dog.hpp"

Dog::Dog()
    : _type("Dog")
{
    std::cout << "Dog Default constructor called" << std::endl;

}

Dog::Dog(const Dog&other)
{
    this->_type = other._type;
    std::cout << "Dog Copy constructor called" << std::endl;

}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->_type = other._type;
    return *this;
}

std::string Dog::getType() const
{
    return this->_type;
}

void    Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}