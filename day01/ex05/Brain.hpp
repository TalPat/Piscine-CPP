#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <string>

class Brain
{
private:
    std::string colour;
public:
    Brain();
    std::string identify();
    ~Brain();
};

#endif