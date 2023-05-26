#include "PMergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(char* argv[], int argc)
		: _argv(argv), _argc(argc)
{   
	try
	{
		PmergeHandler();
		printContainer(this->vec_sequence, "Before");

		double elapsed_time_vec = sortVector();
		double elapsed_time_deq = sortDeque();
		// std::cout << elapsed_time_deq << '\n';
		// std::cout << "here\n";
		
		printContainer(this->vec_sequence, "After");

		std::cout << '\n';
		printTimeComplexity(this->vec_sequence, "vector", elapsed_time_vec);
		printTimeComplexity(this->vec_sequence, "deque", elapsed_time_deq);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this == &rhs)
		return *this;

	_argv = rhs._argv;
	vec_sequence = rhs.vec_sequence;
	deq_sequence = rhs.deq_sequence;

	return *this;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	_argv = copy._argv;
	_argc = copy._argc;
	vec_sequence = copy.vec_sequence;
	deq_sequence = copy.deq_sequence;
}

void    PmergeMe::PmergeHandler()
{
	long    val;

	for (int i = 1; i < _argc; i++)
	{
		char *endptr;
		val = std::strtol(_argv[i], &endptr, 10);
		if (*endptr == '\0' && val >= 0)
			vec_sequence.push_back(val);
		else
			throw InvalidArgumentsException();
	}

	std::copy(this->vec_sequence.begin(), this->vec_sequence.end(), std::back_inserter(this->deq_sequence));
}

template <typename T>
void    PmergeMe::printContainer(const T& container, std::string preMsg)
{
	typename T::const_iterator   it;
	std::cout << preMsg << ": ";
	
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
}

double PmergeMe::sortVector()
{
    clock_t start = clock();

    mergeSort(this->vec_sequence);

    clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;
    
    return elapsed_time;
}

double PmergeMe::sortDeque()
{
    clock_t start = clock();

    mergeSort(this->deq_sequence);

    clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;
    
    return elapsed_time;
}

template <typename T>
void    PmergeMe::insertionSort(T& container)
{
	for (size_t i = 1; i != container.size(); i++)
	{
		long key = container[i];
		long j = i - 1;

		while (j >= 0 && container[j] > key)
		{
			container[j + 1] = container[j];
			j -= 1;
		}
		// std::cout << j << '\n';
		container[j + 1] = key;
		// printContainer(this->vec_sequence,"Step");
	}
}

template <typename T>
void    PmergeMe::mergeSort(T& container)
{
	// clock_t start = clock();

	if (container.size() <= THRESHOLD)
		insertionSort(container);
	else
	{
		T	left(container.begin(), container.begin() + container.size() / 2);
		T	right(container.begin() + container.size() / 2, container.end());

		mergeSort(left);
		mergeSort(right);

		std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
	}

	// clock_t end = clock();

    // double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;
    
    // return elapsed_time;
}

template <typename T>
void    PmergeMe::printTimeComplexity(const T& container, std::string container_name, double time)
{
	std::cout << "Time to process a range of " << container.size() << " elements ";
	std::cout << "with std::" << container_name << " : " << time << " us\n"; 
}

const char* PmergeMe::InvalidArgumentsException::what() const throw()
{
	return "Error: Invalid arguments.";
}