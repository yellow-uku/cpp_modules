#ifndef __WEAPON_H__
# define __WEAPON_H__

#include <iostream>

typedef std::string string;

class Weapon
{
	private:
		string type_;
	
	public:
		Weapon();
		Weapon(string type);
		~Weapon();

		const string& getType();
		void setType(string new_type); 
};

#endif