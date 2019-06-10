#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private:
    int posx, posy, w, h, maxx, maxy;
    std::string design;
public:
    //constructors & destroyers
    Player(int x, int y, int maxx, int maxy);
    Player(Player& obj);
    ~Player();
    void operator = (const Player &p);

    //member functions
    void move(int direction);
    
    int getPosx(void);
    int getPosy(void);
    std::string getDesign(void);
};

#endif