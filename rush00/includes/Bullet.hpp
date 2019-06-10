#ifndef BULLET_HPP
#define BULLET_HPP

#include <string>

class Bullet
{
private:
    int posx, posy, w, h, maxx, maxy, speed, lifespan, index;
    std::string design;
public:
    //constructors & destroyers
    Bullet(int x, int y, int maxx, int maxy, int i);
    Bullet(Bullet& obj);
    ~Bullet();
    void operator = (const Bullet &b);

    //member functions
    int move();
    
    int getPosx(void);
    int getPosy(void);
    std::string getDesign(void);
};

#endif