#ifndef __DIAMOND__H_
# define __DIAMOND__H_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
		std::string	_name;
		using FragTrap::_hit_points; // to access FragTrap class members firstly (which are protected)
		using ScavTrap::_energy_points;
		using FragTrap::_attack_damage;

    public:
		DiamondTrap();
		DiamondTrap(std::string);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &);

		DiamondTrap& operator=(const DiamondTrap &);

        using ScavTrap::attack;

		void	whoAmI();
};

#endif
