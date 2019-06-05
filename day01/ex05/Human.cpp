#include "Human.hpp"
#include "Brain.hpp"
#include <string>
#include <sstream>
#include <iostream>

Human::Human(/* args */)
{
}

Human::~Human()
{
}

std::string Human::identify() {
    return (this->getBrain().identify());
}

Brain &Human::getBrain() {
    return (this->brain);
}