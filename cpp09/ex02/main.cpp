#include "PMergeMe.hpp"

bool checkInput(const std::string str)
{
	if (str.empty())
	{
		std::cout << "Error: Invalid format of int array\n";
		std::cout << "Correct Usage: <int int ...>\n";
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && !(i == 0 && (str[i] == '+' || str[i] == '-')))
		{
			std::cout << "Error: invalid input\n";
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Wrong number of arguments.\n";
		std::cout << "Correct Usage: ./PMergeMe <int int int ...>\n";
		return 1;
	}
	for (int i = 1; i < argc; i++)
		if (!checkInput(argv[i]))
			return 2;
	PmergeMe    arr(argv, argc);
	return 0;
}
