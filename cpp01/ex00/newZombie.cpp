#include "Zombie.hpp"

Zombie* newZombie(const string name)
{
	Zombie *zombie = new Zombie(name);

	return zombie;
}