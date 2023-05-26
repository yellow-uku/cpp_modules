#include "BitcoinExchange.hpp"

bool checkInput(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments.\n";
		std::cout << "Correct Usage: ./btc <filename>\n";
		return false;
	}
	std::ifstream	input;

	input.open(argv[1]);
	if (!input)
	{
		std::cout << "Error: Coudn't open the file.\n";
		return false;
	}

	return true;
}

int main(int argc, char **argv)
{
	if (checkInput(argc, argv))
	{
		try
		{
			BitcoinExchange	btc(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
		
	}
	return 0;
}