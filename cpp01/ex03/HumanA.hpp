#ifndef __HUMAN_A_H__
# define __HUMAN_A_H__

#include <iostream>

#include "Weapon.hpp"

typedef std::string string;

class HumanA
{
	private:
		string name_;
		Weapon& weapon_;

	public:
		HumanA(string name, Weapon& weapon);
		~HumanA();

		void attack();
};

#endif