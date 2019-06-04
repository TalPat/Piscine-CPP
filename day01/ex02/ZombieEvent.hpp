#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <string>
#include "Zombie.hpp"

class ZombieEvent {
  public:
    void setZombieType(std::string type);
    Zombie* newZombie(std::string name);
  private:
    std::string zombieType;
  protected:
};

#endif