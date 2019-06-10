#include "../includes/Star.hpp"

Star::Star(int x, int y, int mx, int my, int i)
{
    this->posx = x;
    this->posy = y;
    this->maxx = mx;
    this->maxy = my;
    this->design = ".";
    this->speed = 800;
    this->lifespan = 0;
    this->index = i;
}

Star::~Star()
{
}

int Star::move() {
    this->lifespan++;
    if (this->lifespan % this->speed == 0) {
        this->posx--;
        this->lifespan = 1;
    }
    if (this->posx < 2) {
        return 1;
    }
    return (0);
}

std::string Star::getDesign(void) {
    return (this->design);
}

int Star::getPosx(void) {
    return (this->posx);
}

int Star::getPosy(void) {
    return (this->posy);
}