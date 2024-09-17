#include "World.h"

World::World() :  m_currLvl(0), m_worldSize(2) {

    m_Hrow = randomCoord();
    m_Hcolumn = randomCoord();

    m_levelsInWorld = new Level[m_worldSize];
     for (int i = 0; i < 2; ++i) {
        m_levelsInWorld[i] = Level(5, 20, 20, 20, 20, 20);
    }
}

World::World(int L, int N, int x, int m, int c, int g, int k) : m_currLvl(0), m_worldSize(L) {

    m_Hrow = randomCoord();
    m_Hcolumn = randomCoord();

    m_levelsInWorld = new Level[L];
    for (int i = 0; i < L; ++i) {
        m_levelsInWorld[i] = Level(N, x, m, c, g, k);
    }

    //currSpot = m_levelsInWorld[0].placeMario(); 
    //currSpotChar = getCurrSpotChar(currSpot);
}

World::~World() {
    delete[] m_levelsInWorld;
}

void World::nextLevel() {
    // if (m_currLvl != m_worldSize) {
    //     m_levelsInWorld[m_currLvl].placePipe();
    // }

    m_currLvl ++;

    m_levelsInWorld[m_currLvl].displayGrid();

    m_Hrow = randomCoord();
    m_Hcolumn = randomCoord();

    m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
}

char World::getCurrSpotChar(int x, int y) {
    int row = x;
    int column = y;

    return m_levelsInWorld[m_currLvl].checkSpot(row, column);

}

void World::displayGrid() {
    m_levelsInWorld[m_currLvl].displayGrid();
}

int World::randomCoord() {
    int coord = (rand() % m_levelsInWorld[m_currLvl].getN());
    return coord;
}

int main(int argc, char const *argv[])
{
    std::cout << "Test";
    World world;
    std::cout << "Test2";
    // world.displayGrid();
    return 0;
}
