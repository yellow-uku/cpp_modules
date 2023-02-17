#include "Dog.hpp"

Dog::Dog()
	: _type("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog&other) : A_Animal(other)
{
	this->_type = other._type;
	this->_brain = new Brain();
	*(this->_brain) = *(other._brain);
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor begin" << std::endl;
	delete _brain;
	std::cout << "Dog Destructor end" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->_type = other._type;
	*(this->_brain) = *(other._brain);
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

Brain*	Dog::getBrain() const
{
	return this->_brain;
}
