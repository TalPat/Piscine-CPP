#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Human.hpp"
#include "Brain.hpp"

class Human
{
private:
    Brain brain;
public:
    Human(/* args */);
    ~Human();
    std::string identify();
    Brain &getBrain();
};

#endif