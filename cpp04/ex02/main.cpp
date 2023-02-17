#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void fun()
{
    const A_Animal* dog = new Dog();
    const A_Animal* cat = new Cat();
    int n = 4;
    A_Animal* animals[n];
    

    for (int i = 0; i < n / 2; ++i)
        animals[i] = new Dog();
    for (int i = n / 2; i < n; ++i)
        animals[i] = new Cat();
    
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < n; ++i)
        delete animals[i];

    // cat->makeSound();
    // dog->makeSound();

    delete dog;
    delete cat;	//should not create a leak
}

void    compare_animals()
{
    Dog dog1;
    Dog dog2;
 //   Dog dog2(dog1);

    dog1.getBrain()->setIdeas("kek");

    dog2.getBrain()->setIdeas("omg");
    dog2 = dog1;

    std::cout << dog1.getBrain()->getIdeas() << std::endl;
    std::cout << dog2.getBrain()->getIdeas() << std::endl;

    dog1.getBrain()->setIdeas("lol");
    std::cout << dog1.getBrain()->getIdeas() << std::endl;
    std::cout << dog2.getBrain()->getIdeas() << std::endl;
}

int main()
{
    fun();
    // compare_animals();  // check deep copy
    return 0;
}