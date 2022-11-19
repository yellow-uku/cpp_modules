#ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"

class Dog: public Animal
{

	private:
		std::string _type;

	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog&);

		Dog& operator=(const Dog &);

		std::string     getType() const;
		void    makeSound() const;
};

#endif