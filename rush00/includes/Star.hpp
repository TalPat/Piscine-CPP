#ifndef STAR_HPP
#define STAR_HPP

#include <string>

class Star
{
private:
    int posx, posy, w, h, maxx, maxy, speed, lifespan, index;
    std::string design;
public:
    //constructors & destroyers
    Star(int x, int y, int maxx, int maxy, int i);
    Star(Star& obj);
    ~Star();
    void operator = (const Star &e);

    //member functions
    int move();
    
    int getPosx(void);
    int getPosy(void);
    std::string getDesign(void);
};

#endif