#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
        : _type("WrongAnimal")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal&other)
{
    this->_type = other._type;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;

}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    this->_type = other._type;
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    return *this;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Wrong Animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}