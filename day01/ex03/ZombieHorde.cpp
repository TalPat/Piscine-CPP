#include <string>
#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {
  //create n zombies with random names
  std::string names[] = {"Bob Ross", "Picasso", "Salvador Dhali", "Polloc", "da Vinci"};
  for (int i = 0; i < N; i++)
  {
    /* code */
  }
  
}

void Zombie::announce() {
  //each member of thee horde must announce
}

Zombie::~Zombie() {
  //remove all zombies
}