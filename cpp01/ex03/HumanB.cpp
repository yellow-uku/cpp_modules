#include "HumanB.hpp"

HumanB::HumanB(string name) : name_(name) {};

HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon& weapon)
{
	weapon_ = &weapon;
}

void HumanB::attack()
{
	std::cout << name_ << " attacks with their weapon " << weapon_->getType() << std::endl;
}