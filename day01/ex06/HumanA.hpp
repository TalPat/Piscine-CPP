#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon weapon;
public:
    HumanA(/* args */);
    ~HumanA();
    void attack();
};

#endif