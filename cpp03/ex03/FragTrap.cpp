#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "No name";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;

    std::cout << "Frag Trap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
        : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;

    std::cout << "Frag Trap Constructor with name " << this->_name << " called " << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Frag Trap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &player)
{
    this->_name = player._name;
    std::cout << "Frag Trap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &player)
{
    this->_name = player._name;
    this->_hit_points = player._hit_points;
    this->_energy_points = player._energy_points;
    this->_attack_damage = player._attack_damage;

    std::cout << "Frag Trap Copy assignment operator called" << std::endl;
    return *this;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "A positive high fives request" << std::endl;
}