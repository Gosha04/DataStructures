#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include <string>
#include <iostream>

class World

{
private:
    Level* m_levelsInWorld;
    int m_currLvl;
    int m_worldSize;
    char currSpotChar;
    int m_Hrow;
    int m_Hcolumn;

public:
    World ();
    World(int L, int N, int x, int m, int c, int g, int k);
    ~World();
    void nextLevel();
    char getCurrSpotChar(int x, int y);
    // int* moveMario();
    std::string displayGrid();
    int randomCoord();
};

#endif