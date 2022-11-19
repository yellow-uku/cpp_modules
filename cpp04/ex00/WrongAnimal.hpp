#ifndef __WANIMAL_H__
# define __WANIMAL_H__

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal&);

		WrongAnimal& operator=(const WrongAnimal &);

		std::string     getType() const;
		void			makeSound() const;
};

#endif