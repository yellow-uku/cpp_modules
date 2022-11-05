#include <iostream>

int	main(int argc, char **argv)
{
	int	i, n;
	std::string	arr;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 2;
		while (i <= argc)
		{
			arr = std::string(argv[i-1]);
			n = std::strlen(argv[i-1]);
			for (int j=0; j<=n; j++)
				std::cout << (char)std::toupper(arr[j]);
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}
