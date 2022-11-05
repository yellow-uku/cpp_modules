#include <iostream>

typedef std::string string;

int main()
{
	string brain = "HI THIS IS BRAIN";
	string	*stringPTR = &brain;
	string	&stringREF = brain;

	std::cout << "ADRESSES:" << std::endl;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "VALUES:" << std::endl;
	std::cout <<  brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}