#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <string>

class ZombieHorde {
  public:
    ZombieHorde(int N);
    ~ZombieHorde();
    void announce();
  private:
    int number;
    Zombie** zombArr;
  protected:
};

#endif