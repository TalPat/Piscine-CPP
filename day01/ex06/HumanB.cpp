#include "HumanB.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(/* args */)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() {
    std::cout << this->name + " attacks with his " + this->weapon.getType;
}