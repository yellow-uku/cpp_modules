#ifndef __SCAV__H_
# define __SCAV__H_

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		~ScavTrap();
		ScavTrap(const ScavTrap &);

		ScavTrap& operator=(const ScavTrap &);

        void guardGate();
};

#endif