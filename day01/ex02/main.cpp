#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

Zombie* randomChump() {
  std::string names[] = {"Bob Ross", "Picasso", "Salvador Dhali", "Polloc", "da Vinci"};
  int index = rand() % 5;
  ZombieEvent myZombieEvent;
  myZombieEvent.setZombieType("Heap Zombie");
  Zombie* heapZombie = myZombieEvent.newZombie(names[index]);
  heapZombie->announce();
  return (heapZombie);
}

int main(void) {
  //the original zombie is created
  Zombie rootZombie("Original zombie", "Stack Zombie");
  rootZombie.announce();
  //the zombie bites a few innocent bystanders
  Zombie* innocentByStander1 = randomChump();
  Zombie* innocentByStander2 = randomChump();
  Zombie* innocentByStander3 = randomChump();
  //chuck norris kills the newly created zombies
  delete innocentByStander1;
  delete innocentByStander2;
  delete innocentByStander3;
  //the original zombie eventually dies from old age
  return (0);
}