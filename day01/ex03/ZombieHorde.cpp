#include <string>
#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"


ZombieHorde::ZombieHorde(int N) {
  srand (time(NULL));
  //create n zombies with random names
  std::string names[] = {"Bob Ross", "Picasso", "Salvador Dhali", "Pollock", "da Vinci"};
  number = N;
  for (int i = 0; i < N; i++)
  {
    Zombie* myZamb = new Zombie(names[rand() % 5], "Zombro");
    zombArr[i] = myZamb;
  }
  // zombArr = horde;
}

void ZombieHorde::announce() {
  for (int i = 0; i < number; i++)
  {
    zombArr[i]->announce();
  }
}

ZombieHorde::~ZombieHorde() {
  for (int i = 0; i < number; i++)
  {
    delete zombArr[i];
  }
}