#include "iter.hpp"
#include "Awesome.hpp"

void    ft_upper(char& c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main()
{
    std::cout << "-------------------------INT ARRAY----------------------" << std::endl;
    
    {
        int	intArray[] = {1, 2, 3, 4, 5};
		int	lenIntArray = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << "Before iteration: ";
		print_arr(intArray, lenIntArray);
		std::cout << std::endl;

		::iter(intArray, lenIntArray, &::ft_power);

		std::cout << "After iteration: ";
		print_arr(intArray, lenIntArray);
		std::cout << "\n\n";
    }

    std::cout << "----------------------STING ARRAY----------------------" << std::endl;
    {
        char charArray[] = {'p', 'e', 'p', 'e', 'g', 'a'};
        int	lenCharArray = sizeof(charArray) / sizeof(charArray[0]);

        std::cout << "Before iteration: ";
		print_arr(charArray, lenCharArray);
		std::cout << std::endl;

        ::iter(charArray, lenCharArray, &::ft_upper);

        std::cout << "After iteration: ";
		print_arr(charArray, lenCharArray);
		std::cout << "\n\n";
    }

    std::cout << "----------------------CLASS---------------------------" << std::endl;

    {
        int tab[] = {0, 1, 2, 3, 4};
        Awesome you[5];

        ::iter(tab, 5, &ft_print);
        std::cout << '\n';
        ::iter(you, 5, &ft_print);
    }

    return 0;
}