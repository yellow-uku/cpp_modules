#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Foo");
	zombie->announce();
	randomChump("Bob");
	delete zombie;
	return (0);
}