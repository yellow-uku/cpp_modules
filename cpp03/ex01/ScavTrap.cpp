#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "No name";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;

    std::cout << "ScavTrap Constructor with " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;

    std::cout << "ScavTrap Constructor with name " << this->_name << " called " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &player)
{
    this->_name = player._name;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &player)
{
    this->_name = player._name;
    this->_hit_points = player._hit_points;
    this->_energy_points = player._energy_points;
    this->_attack_damage = player._attack_damage;

    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}