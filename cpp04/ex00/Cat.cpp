#include "Cat.hpp"

Cat::Cat()
    : _type("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat&other) : Animal(other)
{
    this->_type = other._type;
    std::cout << "Cat Copy constructor called" << std::endl;

}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->Animal::operator=(other);
    return *this;
}

std::string Cat::getType() const
{
    return this->_type;
}

void    Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}