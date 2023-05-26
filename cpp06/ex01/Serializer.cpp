#include "Serializer.hpp"

Serializer::Serializer(void) {
    std::cout << "Default constructor is called" << std::endl;
}

Serializer::~Serializer(void) {
    std::cout << "Destructor is called" << std::endl;
}

Serializer::Serializer(const Serializer & copy) {
    std::cout << "Copy constructor is called" << std::endl;
    *this = copy;
}

Serializer  &Serializer::operator=(const Serializer & copy) {
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)copy;
    return (*this);
}


uintptr_t   Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
