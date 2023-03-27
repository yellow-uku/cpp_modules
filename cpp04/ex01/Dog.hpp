#ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{

	private:
		std::string _type;
		Brain*		_brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog&);

		Dog& operator=(const Dog &);

		std::string     getType() const;
		void    		makeSound() const;
		Brain*			getBrain() const;
};

#endif