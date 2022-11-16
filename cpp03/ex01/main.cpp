#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
   ClapTrap    sam("Sam");
   ScavTrap    jack("Jack");
 //  ClapTrap    unknown;

   std::cout << "----------------" << std::endl;

   sam.attack("Jack");
   jack.takeDamage(90);

   std::cout << "----------------" << std::endl;

   jack.attack("Sam");
   sam.takeDamage(5);

   std::cout << "----------------" << std::endl;

	sam.beRepaired(1);
	jack.beRepaired(10);
	jack.guardGate();

	std::cout << "----------------" << std::endl;
	return 0;
}