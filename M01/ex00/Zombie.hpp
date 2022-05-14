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

};

Zombie *newZombie(const string name);
void randomChump(const string name);

#endif