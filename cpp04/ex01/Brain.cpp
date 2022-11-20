#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

/*
Brain::Brain(const Brain&other)
{
	this->_type = other._type;
	std::cout << "Brain Copy constructor called" << std::endl;

}
*/

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}


Brain& Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}

	std::cout << "Brain Copy assignment operator called" << std::endl;
	return *this;
}

void    Brain::setIdeas(std::string k)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = k;
	}
}

std::string Brain::getIdeas()
{
	return this->ideas[0];
}