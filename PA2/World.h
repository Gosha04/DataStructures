/*
Joshua Vaysman || Dylan Barlava
2449656 || 2428584
vaysman@chapman.edu || dbarlava@chapman.edu
CPSC 350-02
PA2
*/

#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Enemy.h"
#include "Mario.h"
#include <string>
#include <iostream>
#include <random>
#include <fstream>

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
    std::ofstream outFile;

public:
    World ();
    World(int L, int N, int life, int x, int m, int c, int g, int k, std::string output);
    ~World();
    void nextLevel();
    char getCurrSpotChar(int x, int y);
    void displayGrid();
    int randomCoord();
    void move(); // moves mario
    void play();
    Level getLevel(int index);

    // imported from Game
    void interact();
    bool battle(Enemy enemy);
    void warp();
};

#endif