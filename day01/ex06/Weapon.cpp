#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string t) {
    this->type = t;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() {
    return (this->type);
}

void Weapon::setType(std::string newType) {
    this->type = newType;
}