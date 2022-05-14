#include "Zombie.hpp"

void randomChump(const string name)
{
	Zombie zombie(name);

	zombie.announce();
}