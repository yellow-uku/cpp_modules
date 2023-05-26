#include "RPN.hpp"

bool checkInput(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments.\n";
		std::cout << "Correct Usage: ./rpn <math expression RPN>\n";
		return false;
	}
	if (std::string(argv[1]).find_first_not_of("0123456789+-/* ") != std::string::npos)
	{
		std::cout << "Error: invalid arguments.\n";
		return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	if (checkInput(argc, argv))
	{
		try
		{
			RPN rpn(argv[1]);
			std::cout << "Result of the expression: " << rpn.getResult() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
