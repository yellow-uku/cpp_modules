#include "easyfind.hpp"

int main()
{
	std::cout << "--------------------VECTOR--------------------" << std::endl;
	std::vector<int> intArr(4);

	srand (time(NULL));
	for (std::vector<int>::iterator it = intArr.begin(); it != intArr.end(); it++)
		*it = rand() % 10;
	
	std::vector<int>::iterator it;
	
	std::cout << "Vector array:\n";
	for (it = intArr.begin(); it != intArr.end(); it++)
	{
		if (it == intArr.end() - 1)
			std::cout << *it << '\n';
		else
			std::cout << *it << " ";
	}

	for (size_t i = 0; i < intArr.size(); i++)
	{
		if (i == intArr.size() - 1)
			std::cout << intArr[i] << '\n';
		else
			std::cout << intArr[i] << " ";
	}

	try
	{
		std::cout << "Try to find element in the array: " << *easyfind(intArr, 6) << "; ";
		std::cout <<  "position: " << easyfind(intArr, 6) - intArr.begin() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::list<int>	intList;

	for (size_t i = 0; i < 5; i++)
		intList.push_back(i * i);

	std::cout << '\n';

	std::cout << "--------------------LIST--------------------" << std::endl;
	std::cout << "List array:\n";
	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{
		if (std::distance(it, intList.end()) == 1)
			std::cout << *it << '\n';
		else
			std::cout << *it << " ";
	}
	try
	{
		std::cout << "Try to find element in the array: " << *easyfind(intList, 16) << "; ";
		std::cout <<  "position: " << std::distance(intList.begin(), easyfind(intList, 16)) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
