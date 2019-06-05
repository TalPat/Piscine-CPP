#include "HumanA.hpp"

#include <string>
#include <iostream>

HumanA::HumanA(/* args */)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() {
    std::cout << this->name + " attacks with his " + this->weapon.getType;
}
