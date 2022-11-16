#ifndef __CLAP_H__
# define __CLAP_H__

#include <iostream>
#include <cmath>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit_points;	// health
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string);
		~ClapTrap();
		ClapTrap(const ClapTrap &);

		ClapTrap& operator=(const ClapTrap &);

		void attack(const std::string &);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);
};

#endif