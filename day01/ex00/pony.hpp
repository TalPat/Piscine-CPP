#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
  public:
    Pony(std::string call);
    ~Pony();
  private:
    std::string name, colour, age;
};

#endif