#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
private:
    int posx, posy, w, h, maxx, maxy, speed, lifespan, index;
    std::string design;
public:
    //constructors & destroyers
    Enemy(int x, int y, int maxx, int maxy, int i, std::string des, int spd);
    Enemy(Enemy& obj);
    ~Enemy();
    void operator = (const Enemy &e);

    //member functions
    int move();
    
    int getPosx(void);
    int getPosy(void);
    std::string getDesign(void);
};

#endif