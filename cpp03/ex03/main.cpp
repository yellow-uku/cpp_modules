#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"



int main()
{
	FragTrap    jack("Jack");
	DiamondTrap	monster("Monster");

	std::cout << "----------------" << std::endl;

	monster.attack("Jack");
	jack.takeDamage(2);

	std::cout << "----------------" << std::endl;

	jack.attack("Monster");
	monster.takeDamage(4);

	std::cout << "----------------" << std::endl;

	monster.whoAmI();
	std::cout << "----------------" << std::endl;
	return 0;
}