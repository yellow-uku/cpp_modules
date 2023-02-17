#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <iostream>

class A_Animal
{
	protected:
		std::string _type;

	public:
		A_Animal();
		virtual ~A_Animal();
		A_Animal(const A_Animal&);

		A_Animal& operator=(const A_Animal &);

		virtual std::string     getType() const;
		virtual void			makeSound() const = 0;
};

#endif