#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}


Brain::Brain(const Brain&other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];

}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}


Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
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