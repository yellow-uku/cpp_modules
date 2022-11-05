#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

#include <iostream>

typedef std::string string;

class Zombie
{
	private:
		string	name_;

	public:

		Zombie();
		Zombie(const string name);
		~Zombie();

		void announce(void);

		void setName(const string name);

};

Zombie* zombieHorde(int n, string name);

#endif