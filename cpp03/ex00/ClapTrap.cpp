#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
        : _name("No name")
{
    this->_hit_points = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;

    std::cout << "Constructor with " << this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
        : _name(name)
{
    this->_hit_points = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;

    std::cout << "Constructor with name " << this->_name << " called " << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &player)
{
    this->_name = player._name;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &player)
{
    this->_name = player._name;
    this->_hit_points = player._hit_points;
    this->_energy_points = player._energy_points;
    this->_attack_damage = player._attack_damage;

    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points < 1 || this->_energy_points < 1)
    {
        std::cout << "Need more health or energy" << std::endl;
        std::cout << "Number of hit points left: " << this->_hit_points << std::endl;
        std::cout << "Number of energy points left: " << this->_energy_points << "\n" << std::endl;
        return ;
    }
    this->_energy_points--;

    std::cout << this->_name << " attacks " << target;
    std::cout << " causing " << this->_attack_damage << " points of damage" << std::endl;

    std::cout << "Number of hit points left: " << this->_hit_points << std::endl;
    std::cout << "Number of energy points left: " << this->_energy_points << "\n" << std::endl;

}

void    ClapTrap::takeDamage(unsigned int amount)
{   
    if (this->_hit_points > 0)
    {
        std::cout << this->_name << " takes " << amount << " damage points" << std::endl;
        if (this->_hit_points - amount > 0)
        {
            this->_hit_points -= amount;
        }

        std::cout << "Number of hit points left: " << this->_hit_points << std::endl;
        std::cout << "Number of energy points left: " << this->_energy_points << "\n" << std::endl;
        return ;
    }
    std::cout << this->_name << " already died." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points < 1 || this->_energy_points < 1)
    {
        std::cout << "Need more health or energy" << std::endl;
        return ;
    }
    this->_hit_points += amount;
    this->_energy_points--;

    std::cout << this->_name << " repairs " << amount << " hit points" << std::endl;

    std::cout << "Number of hit points left: " << this->_hit_points << std::endl;
    std::cout << "Number of energy points left: " << this->_energy_points << "\n" << std::endl;
}