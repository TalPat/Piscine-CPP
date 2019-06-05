#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string newName, std::string newType): name(newName), type(newType) {
  // name = newName;
  // type = newType;
}

void Zombie::announce() {
  std::cout << name + "(" + type + ") Braaaiiiiiiiiiinnnzz" << "\n";
}

Zombie::~Zombie() {
  std::cout << name + " has died!" << "\n";
}