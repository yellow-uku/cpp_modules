#include "Cat.hpp"

Cat::Cat()
    : _type("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat&other)
{
    this->_type = other._type;
    std::cout << "Cat Copy constructor called" << std::endl;

}

Cat::~Cat()
{
    std::cout << "Cat Destructor begin" << std::endl;
    delete _brain;
    std::cout << "Cat Destructor end" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->_type = other._type;
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