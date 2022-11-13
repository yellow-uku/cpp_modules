#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap    sam("Sam");
	FragTrap    jack("Jack");
//	ClapTrap    unknown;

	std::cout << "----------------" << std::endl;

	sam.attack("Jack");
	jack.takeDamage(5);

	std::cout << "----------------" << std::endl;

	sam.attack("Jack");
	jack.takeDamage(90);

	std::cout << "----------------" << std::endl;

//	sam.beRepaired(1);
	jack.beRepaired(10);
	jack.beRepaired(10);

	std::cout << "----------------" << std::endl;
	
	jack.highFivesGuys();

	std::cout << "----------------" << std::endl;
	return 0;
}