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
    const Dog dog1;
    Dog dog2 = dog1;
    // dog1.getBrain()->setIdeas("kek");
    // Dog dog2(dog1);

    std::cout << "-----------------------------" << std::endl;
    dog1.getBrain()->setIdeas("kek");
    dog2.getBrain()->setIdeas("omg");

    dog2 = dog1;

    std::cout << dog1.getBrain()->getIdeas() << std::endl;
    std::cout << dog2.getBrain()->getIdeas() << std::endl;

    dog1.getBrain()->setIdeas("pepega");
    // dog2.getBrain()->setIdeas("pepega-2");
    std::cout << dog1.getBrain()->getIdeas() << std::endl;
    std::cout << dog2.getBrain()->getIdeas() << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int main()
{
    fun();
    // compare_animals();  // check deep copy
    // while(1);
    return 0;
}