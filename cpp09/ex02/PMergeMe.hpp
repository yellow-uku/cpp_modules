#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

# define THRESHOLD 16

class PmergeMe
{
	private:

		char**				_argv;
		int                 _argc;
		std::vector<long>	vec_sequence;
		std::deque<long>	deq_sequence;

	public:

		PmergeMe();
		PmergeMe(char* argv[], int argc);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &rhs);

		void    PmergeHandler();
		double	sortVector();
		double	sortDeque();

		template <typename T>
		void    printContainer(const T& container, std::string preMsg);

		template <typename T>
		void    printTimeComplexity(const T& container, std::string container_name, double time);

		template <typename T>
		void	mergeSort(T& container);

		template <typename T>
		void    insertionSort(T& container);
		
		class InvalidArgumentsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif