#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal&);

		Animal& operator=(const Animal &);

		virtual std::string     getType() const;
		virtual void			makeSound() const;
};

#endif