#ifndef GAME_H
#define GAME_H

#include "World.h"
#include "Enemy.h"
#include "Mario.h"

class Game
{
private:
    World m_world;
    Enemy m_koopa;
    Enemy m_goomba;
    Enemy m_bowser;
    Mario m_mario;
    char currSpot;
public:
    Game();
    Game(int L, int N, int life);
    ~Game();
    void interact();
    void battle(Enemy enemy);
};

#endif