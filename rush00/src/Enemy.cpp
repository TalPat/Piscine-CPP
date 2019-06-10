#include "../includes/Enemy.hpp"

Enemy::Enemy(int x, int y, int mx, int my, int i, std::string des, int spd)
{
    this->posx = x;
    this->posy = y;
    this->maxx = mx;
    this->maxy = my;
    this->design = des;
    this->speed = spd;
    this->lifespan = 0;
    this->index = i;
}

Enemy::~Enemy()
{
}

int Enemy::move() {
    this->lifespan++;
    if (this->lifespan % this->speed == 0) {
        this->posx--;
    }
    if (this->posx < 2) {
        return 1;
    }
    return (0);
}

std::string Enemy::getDesign(void) {
    return (this->design);
}

int Enemy::getPosx(void) {
    return (this->posx);
}

int Enemy::getPosy(void) {
    return (this->posy);
}