#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public A_Animal
{

	private:
		std::string _type;
		Brain*		_brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat&);

		Cat& operator=(const Cat &);

		std::string     getType() const;
		void            makeSound() const;
};

#endif