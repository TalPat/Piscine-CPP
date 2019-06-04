#include "pony.hpp"
#include <iostream>

Pony::Pony(std::string call) {
    std::cout << "Neigh!!!!\n" + call << "\n";
    name = call;
}

Pony::~Pony() {
    std::cout << name + " is dead\n";
}