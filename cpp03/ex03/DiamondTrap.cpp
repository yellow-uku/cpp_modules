#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "No name";
	this->_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_damage = 20;

	std::cout << "DiamondTrap Default constructor with " << this->_name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;

	std::cout << "DiamondTrap Constructor with name " << this->_name << " called " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &player)
{
	this->_name = player._name;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &player)
{
	this->_name = player._name;
	this->_hit_points = player._hit_points;
	this->_energy_points = player._energy_points;
	this->_attack_damage = player._attack_damage;

	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return *this;
}

void    DiamondTrap::whoAmI()
{
	std::cout << "Diamond Trap name: " << this->_name << std::endl;
	std::cout << "Clap Trap name: " << ClapTrap::_name << std::endl; 
}