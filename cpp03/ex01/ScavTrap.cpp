#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "No name";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;

    std::cout << "Scav Trap Constructor with " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;

    std::cout << "Scav Trap Constructor with name " << this->_name << " called " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav Trap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &player)
{
    this->_name = player._name;
    std::cout << "Scav Trap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &player)
{
    this->_name = player._name;
    this->_hit_points = player._hit_points;
    this->_energy_points = player._energy_points;
    this->_attack_damage = player._attack_damage;

    std::cout << "Scav Trap Copy assignment operator called" << std::endl;
    return *this;
}

void    ScavTrap::attack(const std::string &target)
{
    std::cout << "Scav Trap " << this->_name << " attacks " << target;
    std::cout << " causing " << this->_attack_damage << " points of damage" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "Scav Trap is now in Gatekeeper mode" << std::endl;
}