#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	std::string level;
	level = av[1];

	if (ac != 2)
	{
		harl.complain("ERROR");
		return (1);
	}
	int level_id = harl.get_level_id(level);

	switch(level_id)
	{
		case 0:
				harl.complain("DEBUG");
				break ;
		case 1:
				harl.complain("INFO");
				break ;
		case 2:
				harl.complain("WARNING");
				break ;
		case 3:
				harl.complain("ERROR");
				break ;
		default:
				std::cout << "Harl doesn't know any comments of this type!\n";
	}
	return (0);
}