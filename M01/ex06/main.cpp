#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return 0;
}