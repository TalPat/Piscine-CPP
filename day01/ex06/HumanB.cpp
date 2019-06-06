#include "HumanB.hpp"
#include "Weapon.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(std::string newName): name(newName) {
}

HumanB::~HumanB() {
}

void HumanB::attack() {
    std::cout << this->name + " attacks with his " + this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon) {
    this->weapon = &newWeapon;
}