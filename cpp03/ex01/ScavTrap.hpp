#ifndef __SCAV__H_
# define __SCAV__H_

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		~ScavTrap();
		ScavTrap(const ScavTrap &);

		ScavTrap& operator=(const ScavTrap &);

		void attack(const std::string &);
        void guardGate();
};

#endif