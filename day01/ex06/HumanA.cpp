#include "HumanA.hpp"
#include "Weapon.hpp"

#include <string>
#include <iostream>

HumanA::HumanA(std::string newName, Weapon &newWeapon): name(newName), weapon(newWeapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() {
    std::cout << this->name + " attacks with his " + this->weapon.getType() << std::endl;
}
