#include "../includes/Player.hpp"

Player::Player(int x, int y, int mx, int my)
{
    this->posx = x;
    this->posy = y;
    this->maxx = mx;
    this->maxy = my;
    this->design = ">";
}

Player::~Player()
{
}

void Player::move(int direction) {
    switch (direction)
    {
    case 0://Up
        this->posy--;
        if (this->posy < 1) this->posy = 1;
        break;
    case 1://Down
        this->posy++;
        if (this->posy > this->maxy-7) this->posy = this->maxy-7;
        break;
    case 2://Left
        this->posx--;
        if (this->posx < 1) this->posx = 1;
        break;
    case 3://Right
        this->posx++;
        if (this->posx > this->maxx-2) this->posx = this->maxx-2;
        break;
    
    default:
        break;
    }
}

std::string Player::getDesign(void) {
    return (this->design);
}

int Player::getPosx(void) {
    return (this->posx);
}

int Player::getPosy(void) {
    return (this->posy);
}