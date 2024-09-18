#include "World.h"
#include <random>

World::World() :  m_currLvl(0), m_worldSize(2) {

    m_N = 5;
    m_levelsInWorld = new Level[m_worldSize];
     for (int i = 0; i < m_worldSize - 1; ++i) {
        m_levelsInWorld[i] = Level(m_N, 20, 20, 20, 20, 20);
        m_levelsInWorld[i].placePipe();
    }
    m_levelsInWorld[m_worldSize-1].placePipe();

    while (true) {
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        }
        else {
            continue;
        }
    }
    srand(time(NULL));
}

World::World(int L, int N, int x, int m, int c, int g, int k) : m_currLvl(0), m_worldSize(L) {

    m_N = N;
    m_levelsInWorld = new Level[m_worldSize];
     for (int i = 0; i < m_worldSize - 1; ++i) {
        m_levelsInWorld[i] = Level(m_N, x, m, c, g, k);
        m_levelsInWorld[i].placePipe();
    }
    m_levelsInWorld[m_worldSize-1].placePipe();

    while (true) {
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        }
        else {
            continue;
        }
    }
    srand(time(NULL));
}

World::~World() {
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

// void World::move() {
//     int oldRow = m_Hrow;
//     int oldColumn = m_Hcolumn;
//     int newRow;
//     int newColumn;

//     // generates a random number between 0-3
//     int direction = (rand() % 4);
//     // if direction is 0 move up
//     switch (direction) {
//     case 0:
//         newRow = (m_Hrow - 1 + m_N) % m_N;
//         newColumn = m_Hcolumn;
//         std::cout << "Mario moved up" << std::endl;

//     // if direction is 1 move right
//     case 1:
//         newRow = m_Hrow;
//         newColumn = (m_Hcolumn + 1) % m_N;
//         std::cout << "Mario moved right" << std::endl;
    
//     // if direction is 2 move down
//     case 2:
//         newRow = (m_Hrow + 1) % m_N;
//         newColumn = m_Hrow;
//         std::cout << "Mario moved down" << std::endl;

//     // if direction is 3 move left
//     case 3:
//         newRow = m_Hrow;
//         newColumn = (m_Hcolumn - 1 + m_N) % m_N;
//         std::cout << "Mario moved left" << std::endl;
//     }

// }

int main(int argc, char const *argv[])
{
    std::cout << "Test";
    World world(3, 5, 20, 20, 20, 20, 20);
    std::cout << "Grid pointer: " << world.getLevel(0).getGrid() << std::endl;
    std::cout << "Test2\n";
    
    world.displayGrid();

    //world.move();
    return 0;
}
