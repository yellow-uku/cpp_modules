#include "Cat.hpp"

Cat::Cat()
    : _type("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat&other) : A_Animal(other)
{
	this->_type = other._type;
	this->_brain = new Brain();
	*(this->_brain) = *(other._brain);
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
	*(this->_brain) = *(other._brain);
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