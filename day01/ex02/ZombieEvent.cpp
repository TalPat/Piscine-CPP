#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type) {
  zombieType = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
  Zombie* newZambino = new Zombie(name, zombieType);
  return (newZambino);
}