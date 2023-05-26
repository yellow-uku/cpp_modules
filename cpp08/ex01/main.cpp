#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "----------- TEST 0: from subject -----------\n\n";
		Span sp = Span(5);
		std::cout << '\n';

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printVector();
		std::cout << '\n';

		std::cout << "Shortest Distance: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Distance: " << sp.longestSpan() << std::endl;
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	try
	{
		std::cout << "----------- TEST 1: array size < 2 -----------\n\n";

		Span span = Span(1);
		std::cout << '\n';

		span.addNumber(6);

		span.printVector();
		std::cout << '\n';

		std::cout << "Shortest Distance: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Distance: " << span.longestSpan() << std::endl;
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << "----------- TEST 2: try to add to a full array -----------\n\n";

		Span span = Span(2);
		std::cout << '\n';

		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);

		span.printVector();
		std::cout << '\n';

		std::cout << "Shortest Distance: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Distance: " << span.longestSpan() << std::endl;
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try
	{
		std::cout << "----------- TEST 3: add range of numbers to array -----------\n\n";

		Span sp = Span(10);
		std::cout << '\n';

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.addNumbersRange(sp.begin() + 5, sp.end() - 1, 445);
		
		sp.addNumber(1);
		sp.printVector();
		
		std::cout << '\n';

		std::cout << "Shortest Distance: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Distance: " << sp.longestSpan() << std::endl;
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}