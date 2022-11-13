#ifndef __FRAG_H__
# define __FRAG_H__

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
		FragTrap();
		FragTrap(std::string);
		~FragTrap();
		FragTrap(const FragTrap &);

		FragTrap& operator=(const FragTrap &);

        void highFivesGuys(void);
};

#endif
