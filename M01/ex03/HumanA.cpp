#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon& weapon) : name_(name), weapon_(weapon){};
HumanA::~HumanA(){};

void HumanA::attack()
{
	std::cout << name_ << " attacks with their weapon " << weapon_.getType() << std::endl;
}