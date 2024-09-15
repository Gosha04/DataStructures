#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

class World

{
private:
    Level m_level;
    int m_currLvl;
    int m_worldSize;

public:
    World ();
    World(int L, int N);
    ~World();
    char nextLevel();
};

#endif