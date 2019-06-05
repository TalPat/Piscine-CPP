#include <string>
#include "Brain.hpp"
#include <sstream>
#include<iostream>

Brain::Brain(/* args */)
{
}

Brain::~Brain()
{
}

std::string Brain::identify() {
    std::stringstream address;
    address << this;
    return (address.str());
}
