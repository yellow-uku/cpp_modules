#include "Weapon.hpp"

Weapon::Weapon(string type): type_(type){}
Weapon::~Weapon(){}
Weapon::Weapon(){}

const string&	Weapon::getType() {return type_;}

void Weapon::setType(string new_type) {type_ = new_type;}