#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void fun()
{
    // A_Animal animal;
    const A_Animal* dog = new Dog();
    const A_Animal* cat = new Cat();
    int n = 4;
    A_Animal* animals[n];

    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < n / 2; ++i)
        animals[i] = new Dog();
    for (int i = n / 2; i < n; ++i)
        animals[i] = new Cat();
    
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < n; ++i)
        delete animals[i];

    std::cout << "-----------------------------" << std::endl;
    cat->makeSound();
    dog->makeSound();

    std::cout << "-----------------------------" << std::endl;
    delete dog;
    delete cat;
}

void    compare_animals()
{
    Dog* firstDog = new Dog();
    firstDog->getBrain()->setIdeas("kek");
    Dog* secondDog = new Dog();
    secondDog->getBrain()->setIdeas("omg");
    *firstDog = *secondDog;

    std::cout << "-----------------------------" << std::endl;
    delete firstDog;
    delete secondDog;
}

int main()
{
    fun();
    // compare_animals();  // check deep copy
    // while(1);
    return 0;
}