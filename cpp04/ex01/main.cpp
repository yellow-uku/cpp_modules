#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void fun()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    int n = 4;
    Animal* animals[n];

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
    // const Animal* dog1 = new Dog();
    // const Animal* dog2 = new Dog();

    Dog dog1;
 //   Dog dog2;
 //   Dog dog2(dog1);

 //   dog1 = dog2;
    dog1.getBrain()->setIdeas("kek");
    Dog dog2(dog1);

    std::cout << dog1.getBrain()->getIdeas();
    std::cout << dog2.getBrain()->getIdeas();
    // if (dog1.getBrain() == dog2.getBrain())
    // {

    //     std::cout << "same brain" << std::endl;
    // }
    // else
    // {
    //     std::cout << "1st brain: " << s
    //     std::cout << "fuck" << std::endl;
    // }
    
    // delete dog2;
    // delete dog1;
}

int main()
{

 //   fun();
    compare_animals();
    while(1){};
return 0;
}