#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Enemy.h"
#include "Mario.h"
#include <string>
#include <iostream>
#include <random>

class World

{
private:
    Level* m_levelsInWorld;
    int m_currLvl;
    int m_worldSize;
    int m_Hrow;
    int m_Hcolumn;
    Enemy m_koopa;
    Enemy m_goomba;
    Enemy m_bowser;
    Mario m_mario;
    char currSpotChar;

public:
    World ();
    World(int L, int N, int life, int x, int m, int c, int g, int k);
    ~World();
    void nextLevel();
    char getCurrSpotChar(int x, int y);
    // int* moveMario();
    void displayGrid();
    int randomCoord();
    void move(); // moves mario
    void play();
    Level getLevel(int index);

    // imported from Game
    void interact();
    void battle(Enemy enemy);
    void warp();
};

#endif