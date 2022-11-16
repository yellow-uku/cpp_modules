#ifndef __ANIMAL_H__
# define __ANIMAL_H__

class Animal
{
    private:
        std::string _type;
    public:
        Animal();
        ~Animal();
        Animal(const Animal&);

        Animal& operator=(const Animal &);

        void    makeSound();
};

#endif