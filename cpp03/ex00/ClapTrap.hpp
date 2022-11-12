#ifndef __TRAP_H__
# define __TRAP_H__

#include <iostream>
#include <cmath>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;	// health
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string);
		~ClapTrap();
		ClapTrap(const ClapTrap &);

		ClapTrap& operator=(const ClapTrap &);

		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

};

#endif