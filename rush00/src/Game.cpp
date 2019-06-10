#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include "../includes/Game.hpp"
#include "../includes/Player.hpp"
#include <ctime>
#include <sstream>


Game::Game() {
    initscr();
    curs_set(0);
    refresh();
    getmaxyx(stdscr, this->sizey, this->sizex);
    this->hp = 100;
    this->time = 0;
    this->score = 0;
    this->bulletIndex = 0;
    this->enemyIndex = 0;
    this->starIndex = 0;
    this->rate = 0;
    this->winMain = newwin(this->sizey - 5, this->sizex, 0, 0);
    box(this->winMain, 0, 0);
    this->winStats = newwin(5, this->sizex, this->sizey - 5, 0);
    box(this->winStats, 0, 0);
    keypad(stdscr, TRUE);
    noecho();
    mvwprintw(this->winMain, (LINES-3)/2, (COLS/2)-(17/2), "PREPARE YOURSELF");
    mvwprintw(this->winMain, (LINES-3)/2+1, (COLS/2)-(26/2), "PRESS ANY KEY TO CONTINUE");
    wrefresh(this->winMain);
    wrefresh(this->winStats);

    getch();
    this->play();
}

Game::~Game() {
    delete this->player;
    endwin();
}

void Game::play(void) {
    int playermove;

    this->start = std::time(0);
    this->player = new Player(this->sizex/2, this->sizey/2, this->sizex, this->sizey);
    this->render();
    int ch= 0;
    timeout(1);
    while((ch=getch())!= 'q')
    {
        switch(ch)
        {
            case KEY_UP:
                playermove= 0; 
                break;
            case KEY_DOWN:
                playermove= 1;
                break;
            case KEY_LEFT:
                playermove= 2;
                break;
            case KEY_RIGHT:
                playermove= 3;
                break;
            case ' ':
                this->fire();
                break;
        }
        if (rand()%1000 > (996)) {
            int enemyref = rand()%this->enemyIndex;
            this->enemy[this->enemyIndex] = new Enemy(this->enemy[enemyref]->getPosx() - 1, this->enemy[enemyref]->getPosy(), this->sizex, this->sizey, this->enemyIndex, "-", 10);
            this->enemyIndex++;
        }
        if (rand()%1000 > (996 - this->rate)) {
            this->enemy[this->enemyIndex] = new Enemy(this->sizex - 2, rand()%(this->sizey - 7) + 1, this->sizex, this->sizey, this->enemyIndex, "<", 20);
            this->enemyIndex++;
        }
        if (rand()%10000 > (9995)) {
            this->star[this->starIndex] = new Star(this->sizex - 2, rand()%(this->sizey - 7) + 1, this->sizex, this->sizey, this->starIndex);
            this->starIndex++;
        }
        if (rand()%10000 > (9995)) {
            this->rate++;
        }
        this->player->move(playermove);
        for (int i = 0; i < this->bulletIndex; i++)
        {
            if(bullet[i]->move() == 1) {
                this->removeBullet(i);
            }
        }
        for (int i = 0; i < this->enemyIndex; i++)
        {
            if(enemy[i]->move() == 1) {
                this->removeEnemy(i);
            }
        }
        for (int i = 0; i < this->starIndex; i++)
        {
            if(star[i]->move() == 1) {
                this->removeStar(i);
            }
        }
        this->collisionCheck();
        playermove = 4;
        ch = 0;
        this->render();
        if (this->hp <= 0) {
            wclear(this->winMain);
            box(this->winMain, 0, 0);
            mvwprintw(this->winMain, (LINES-3)/2, (COLS/2)-(10/2), "GAME OVER");
            wrefresh(this->winMain);
            sleep(2);
            break ;
        }
    }
}

void Game::render() {
    char playerDesign[this->player->getDesign().length() + 1];

    this->player->getDesign().copy(playerDesign, this->player->getDesign().length() + 1);
    playerDesign[this->player->getDesign().length()] = '\0';

    werase(this->winMain);
    box(this->winMain, 0, 0);
    this->renderStars();
    mvwprintw(this->winMain, this->player->getPosy(), this->player->getPosx(), playerDesign); //render player
    this->renderBullets(); //render bullet
    this->renderEnemies();
    this->renderStats();
    wrefresh(this->winMain);
    wrefresh(this->winStats);
}

void Game::renderBullets() {
    for (int i = 0; i < this->bulletIndex; i++)
    {
        char bulletDesign[this->bullet[i]->getDesign().length() + 1];

        this->bullet[i]->getDesign().copy(bulletDesign, this->bullet[i]->getDesign().length() + 1);
        bulletDesign[this->bullet[i]->getDesign().length()] = '\0';

        mvwprintw(this->winMain, this->bullet[i]->getPosy(), this->bullet[i]->getPosx(), bulletDesign);
    }
}

void Game::renderEnemies() {
    for (int i = 0; i < this->enemyIndex; i++)
    {
        char design[this->enemy[i]->getDesign().length() + 1];

        this->enemy[i]->getDesign().copy(design, this->enemy[i]->getDesign().length() + 1);
        design[this->enemy[i]->getDesign().length()] = '\0';

        mvwprintw(this->winMain, this->enemy[i]->getPosy(), this->enemy[i]->getPosx(), design);
    }
}

void Game::renderStars() {
    for (int i = 0; i < this->starIndex; i++)
    {
        char design[this->star[i]->getDesign().length() + 1];

        this->star[i]->getDesign().copy(design, this->star[i]->getDesign().length() + 1);
        design[this->star[i]->getDesign().length()] = '\0';

        mvwprintw(this->winMain, this->star[i]->getPosy(), this->star[i]->getPosx(), design);
    }
}

void Game::renderStats() {
    char hpbuffer[200];
    sprintf(hpbuffer, "HP: %d", this->hp);
    char timebuffer[200];
    sprintf(timebuffer, "TIME: %ld", std::time(0) - this->start);
    char scorebuffer[200];
    sprintf(scorebuffer, "SCORE: %d", this->score);

    werase(this->winStats);
    box(this->winStats, 0, 0);
    mvwprintw(this->winStats, (2), (2), scorebuffer);
    mvwprintw(this->winStats, (2), (COLS/2)-(10/2), timebuffer);
    mvwprintw(this->winStats, (2), (COLS)-(10), hpbuffer);
}

void Game::removeBullet(int i) {
    delete this->bullet[i];
    for (int j = i; j < this->bulletIndex; j++)
    {
        this->bullet[j] = this->bullet[j+1];
    }
    this->bulletIndex--;
}

void Game::removeEnemy(int i) {
    delete this->enemy[i];
    for (int j = i; j < this->enemyIndex; j++)
    {
        this->enemy[j] = this->enemy[j+1];
    }
    this->enemyIndex--;
}

void Game::removeStar(int i) {
    delete this->star[i];
    for (int j = i; j < this->starIndex; j++)
    {
        this->star[j] = this->star[j+1];
    }
    this->starIndex--;
}

void Game::fire() {
    this->bullet[this->bulletIndex] = new Bullet(this->player->getPosx() + 1, this->player->getPosy(), this->sizex, this->sizey, this->bulletIndex); // make new bullet
    this->bulletIndex++;
}

// Check for collition with enemy
void Game::collisionCheck() {

    for (int i = 0; i < this->bulletIndex; i++) {
        for (int j = 0; j < this->enemyIndex; j++) {
            if (this->bullet[i]->getPosx() == this->enemy[j]->getPosx() && this->bullet[i]->getPosy() == this->enemy[j]->getPosy()) {
                this->removeBullet(i);
                this->removeEnemy(j);
                this->score++;
                i--;
            }
        }
    }
    for (int i = 0; i < enemyIndex; i++) {
        if (this->player->getPosx() == this->enemy[i]->getPosx() && this->player->getPosy() == this->enemy[i]->getPosy()) {
            this->removeEnemy(i);
            i--;
            this->hp = this->hp - 20;
        }
    }
    
}

void Game::setBulletIndex(int i) {
    this->bulletIndex = i;
}

int Game::getBulletIndex() {
    return (this->bulletIndex);
}

int Game::getSizex() {
    return (this->sizex);
}

int Game::getSizey() {
    return (this->sizey);
}