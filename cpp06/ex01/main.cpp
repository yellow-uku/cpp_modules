#include "Serializer.hpp"

int main()
{
    Data *start = new Data;
    start->int_obj = 5;
    start->double_obj = 5.5;
    start->str_obj = "Pepega";
    
    std::cout << "Before deserialization:" << std::endl;
	std::cout << "int: " << start->int_obj << std::endl;
	std::cout << "double: " << start->double_obj << std::endl;
	std::cout << "string: " << start->str_obj << std::endl;
    std::cout << std::endl;

    uintptr_t test = Serializer::serialize(start);
    Data *deserialized_obj = Serializer::deserialize(test);

    std::cout << "Result of deserialization:" << std::endl;
	std::cout << "int: " << deserialized_obj->int_obj << std::endl;
	std::cout << "double: " << deserialized_obj->double_obj << std::endl;
	std::cout << "string: " << deserialized_obj->str_obj << std::endl;
    std::cout << std::endl;

    if (deserialized_obj == start)
        std::cout << "Pointers are equal." << std::endl;

    delete start;
    
    return 0;
}