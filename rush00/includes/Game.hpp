#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include <ctime>
#include "Star.hpp"

class Game
{
private:
    int sizex, sizey, ready, bulletIndex, enemyIndex, starIndex, hp, time, score, rate;
    WINDOW *winMain, *winStats;
    Player *player;
    Bullet *bullet[255];
    Enemy *enemy[1023];
    Star *star[1023];
    time_t start;
public:
    //constructors & destroyers
    Game();
    Game(Game& obj);
    ~Game();
    void operator = (const Game &g);

    //member functions
    void play();

    void render();
    void renderBullets();
    void renderEnemies();
    void renderStars();
    void renderStats();

    void collisionCheck();
    void fire();
    void removeBullet(int i);
    void removeEnemy(int i);
    void removeStar(int i);

    void setBulletIndex(int i);
    int getBulletIndex();
    int getSizex();
    int getSizey();
};

#endif