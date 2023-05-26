#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "ERROR: Invalid num of argument!" << std::endl;
        std::cout << "Usage: ./convert + 'your argument'" << std::endl;
        return (false);
    }

    return (ScalarConverter::convertAll(argv[1]));
}\