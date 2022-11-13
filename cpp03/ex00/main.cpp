#include "ClapTrap.hpp"

int main()
{
    ClapTrap    sam("Sam");
 //   ClapTrap    another_player(sam);
    ClapTrap    jack("Jack");
    ClapTrap    unknown;

 //   jack = another_player;

    std::cout << "----------------" << std::endl;

    sam.attack("Jack");
    jack.takeDamage(10);

    jack.attack("Sam");
    sam.takeDamage(5);

    sam.beRepaired(1);
    jack.beRepaired(2);
    std::cout << "----------------" << std::endl;
    return 0;
}