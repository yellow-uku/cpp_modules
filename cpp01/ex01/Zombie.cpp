#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const string name)
{
	name_ = name;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called: zombie " << name_ << std::endl;
}

void Zombie::announce()
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const string name)
{
	this->name_ = name;
}