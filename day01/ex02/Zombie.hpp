#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  public:
    Zombie(std::string newName, std::string newType);
    void announce();
    ~Zombie();
  private:
    std::string name, type;
  protected:
};

#endif