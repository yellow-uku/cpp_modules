#ifndef __WCAT_H__
# define __WCAT_H__

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	private:
		std::string _type;

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat&);

		WrongCat& operator=(const WrongCat &);

		std::string     getType() const;
		void            makeSound() const;
};

#endif