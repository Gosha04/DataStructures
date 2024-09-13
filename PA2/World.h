#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

class World

{
private:
    Level level;

public:
    World ();
    World(int L);
    ~World();
};

#endif