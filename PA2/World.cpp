#include "World.h"

World::World() :  m_currLvl(0), m_worldSize(2) {

    m_levelsInWorld = new Level[m_worldSize];
     for (int i = 0; i < m_worldSize - 1; ++i) {
        m_levelsInWorld[i] = Level(5, 20, 20, 20, 20, 20);
        m_levelsInWorld[i].placePipe();
    }
    m_levelsInWorld[m_worldSize-1].placePipe();

    while (true) {
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        if ((m_levelsInWorld[m_currLvl][m_Hrow][m_Hcolumn] != 'b') && (m_levelsInWorld[m_currLvl][m_Hrow][m_Hcolumn] != 'w')) {
            m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        }
        else {
            continue;
        }
    }
}

World::World(int L, int N, int x, int m, int c, int g, int k) : m_currLvl(0), m_worldSize(L) {

    m_levelsInWorld = new Level[m_worldSize];
     for (int i = 0; i < m_worldSize - 1; ++i) {
        m_levelsInWorld[i] = Level(5, 20, 20, 20, 20, 20);
        m_levelsInWorld[i].placePipe();
    }
    m_levelsInWorld[m_worldSize-1].placePipe();

    while (true) {
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        if ((m_levelsInWorld[m_currLvl][m_Hrow][m_Hcolumn] != 'b') && (m_levelsInWorld[m_currLvl][m_Hrow][m_Hcolumn] != 'w')) {
            m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        }
        else {
            continue;
        }
    }
}

World::~World() {
    for (int i = 0; i < m_worldSize; ++i) {
        for (int j = 0; j < m_levelsInWorld[i].getN(); ++j) {
            delete[] m_levelsInWorld[i].getGrid()[j];
        }
    }
    delete[] m_levelsInWorld;
}

void World::nextLevel() {

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

Level World::getLevel(int index) {
    return m_levelsInWorld[index];
}

int World::randomCoord() {
    int coord = (rand() % m_levelsInWorld[m_currLvl].getN());
    return coord;
}

int main(int argc, char const *argv[])
{
    std::cout << "Test";
    World world(3, 5, 20, 20, 20, 20, 20);
    std::cout << "Grid pointer: " << world.getLevel(0).getGrid() << std::endl;
    std::cout << "Test2\n";
    
    world.displayGrid();
    return 0;
}
