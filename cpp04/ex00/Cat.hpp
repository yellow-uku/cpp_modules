#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		std::string _type;

	public:
		Cat();
		~Cat();
		Cat(const Cat&);

		Cat& operator=(const Cat &);

		std::string     getType() const;
		void            makeSound() const;
};

#endif