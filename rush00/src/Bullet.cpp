#include "../includes/Bullet.hpp"

Bullet::Bullet(int x, int y, int mx, int my, int i)
{
    this->posx = x;
    this->posy = y;
    this->maxx = mx;
    this->maxy = my;
    this->design = "-";
    this->speed = 20;
    this->lifespan = 0;
    this->index = i;
}

Bullet::~Bullet()
{
}

int Bullet::move() {
    this->lifespan++;
    if (this->lifespan % this->speed == 0) {
        this->posx++;
    }
    if (this->posx > this->maxx - 2) {
        return 1;
    }
    return (0);
}

std::string Bullet::getDesign(void) {
    return (this->design);
}

int Bullet::getPosx(void) {
    return (this->posx);
}

int Bullet::getPosy(void) {
    return (this->posy);
}