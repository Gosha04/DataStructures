#include "World.h"

World::World() :  m_currLvl(0), m_worldSize(0) {
    
}

World::World(int L, int N, int x, int m, int c, int g, int k) : m_currLvl(0), m_worldSize(L) {
    m_levelsInWorld = new Level[L];
    for (int i = 0; i < L; ++i) {
        m_levelsInWorld[i] = Level(N, x, m, c, g, k);
    }

    currSpot = nextLevel(); 
    currSpotChar = getCurrSpotChar(currSpot);
}

World::~World() {

}

int* World::nextLevel() {
    if (m_currLvl != m_worldSize) {
        m_levelsInWorld[m_currLvl - 1].placePipe();
    }

    m_currLvl ++;

    m_levelsInWorld[m_currLvl - 1].displayGrid();

    return m_levelsInWorld[m_currLvl - 1].placeMario();
}

char World::getCurrSpotChar(int* coords) {
    int row = coords[0];
    int column = coords[1];

    return m_levelsInWorld[m_currLvl - 1].checkSpot(row, column);

}

int* World::getCurrSpot() {
    return currSpot;
}

void World::displayGrid() {
    m_levelsInWorld[m_currLvl - 1].displayGrid();
}

int main(int argc, char const *argv[])
{
    World world(3, 5, 4, 20, 26, 25, 25);
    world.displayGrid();
    return 0;
}
