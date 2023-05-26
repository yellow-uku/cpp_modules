#include "Array.hpp"
#include <ctime>
#include <ctime>
#include <iomanip>

int main()
{
    std::cout << "--------------------- TEST 1 ---------------------------------" << std::endl;
    {
        Array<int> intArray(10);
        Array<int> intArray2(10);
        int *mirror = new int[10];

        std::srand(std::time(NULL));
        for (int i = 0; i < 10; i++)
        {
            int const value = std::rand() % 100;

            intArray[i] = value;
            mirror[i] = value;
        }

        for (int i = 0; i < 10; i ++)
        {
            std::cout << "intArray[" << i << "] = " << std::setw(3) << intArray[i] << "   |   ";
			std::cout << "mirror[" << i << "] = " << std::setw(3) << mirror[i] << std::endl;
        }

        delete [] mirror;
    }




    std::cout << "--------------------- TEST 2 ---------------------------------" << std::endl;

    Array<int> intArray(42);
    int *mirror = new int[42];

    srand(time(NULL));
    for (int i = 0; i < 42; i++)
    {
        int const value = rand() % 100;

        intArray[i] = value;
        mirror[i] = value;
    }


    std::cout << "------------------------------------------------------------" << std::endl;
    {
        Array<int> tmp = intArray;
        Array<int> test(tmp);
    }

    for (int i = 0; i < 42; i++)
    {
        if (mirror[i] != intArray[i])
        {
            std::cerr << "didn't save value!!" << std::endl;
            return (1);
        }
    }

    std::cout << "------------------------------------------------------------" << std::endl;
    try
    {
        intArray[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


	std::cout << "------------------------------------------------------------" << std::endl;
    try
    {
        intArray[42] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    for (int i = 0; i < (int)intArray.size(); i++)
    {
        intArray[i] = std::rand() % 100;
    }

    delete [] mirror;
	return 0;
}