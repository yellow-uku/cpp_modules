#ifndef __HUMAN_B_H__
# define __HUMAN_B_H__

#include <iostream>

#include "Weapon.hpp"

typedef std::string string;

class HumanB
{
	private:
		string name_;
		Weapon* weapon_;

	public:
		HumanB(string name);
		~HumanB();

		void setWeapon(Weapon& weapon);
		void attack();
};

#endif