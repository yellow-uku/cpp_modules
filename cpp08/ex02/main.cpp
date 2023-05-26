#include "MutantStack.hpp"

int main()
{
	std::cout << "--------------------MUTANT STACK--------------------" << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top value in stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of the stack after popping top value: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "-- Mutant Stack (iterate from bottom to top) --\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "--------------------LIST--------------------" << std::endl;

	std::list<int>	intList;

	intList.push_back(5);
	intList.push_back(17);

	std::cout << "Last element in list: " << intList.back() << std::endl;

	intList.pop_back();

	std::cout << "Size of the list after removing last element: " << intList.size() << std::endl;

	intList.push_back(3);
	intList.push_back(5);
	intList.push_back(737);
	intList.push_back(0);

	std::list<int>::iterator it_list = intList.begin();
	std::list<int>::iterator ite_list = intList.end();

	++it_list;
	--it_list;
	
	std::cout << "--  List  --\n";
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	return 0;
}