#include "World.h"

// World::World() :  m_currLvl(0), m_worldSize(2) {

//     m_Hrow = randomCoord();
//     m_Hcolumn = randomCoord();

//     m_levelsInWorld = new Level[m_worldSize];
//      for (int i = 0; i < 2; ++i) {
//         m_levelsInWorld[i] = Level(5, 20, 20, 20, 20, 20);
//     }
// }

// World::World(int L, int N, int x, int m, int c, int g, int k) : m_currLvl(0), m_worldSize(L) {

//     m_Hrow = randomCoord();
//     m_Hcolumn = randomCoord();

//     m_levelsInWorld = new Level[L];
//     for (int i = 0; i < L; ++i) {
//         m_levelsInWorld[i] = Level(N, x, m, c, g, k);
//     }

//     //currSpotChar = getCurrSpotChar(currSpot);
// }

World::World() {
    m_currLvl = 0;
    m_worldSize = 2;

    m_Hrow = randomCoord();
    m_Hcolumn = randomCoord();

    m_levelsInWorld = new Level[m_worldSize];
    
    for (int i = 0; i < 2; ++i) {
        m_levelsInWorld[i] = Level(5, 20, 20, 20, 20, 20);
    }


}

World::~World() {
    delete[] m_levelsInWorld;
}

void World::nextLevel() {
    if (m_currLvl != m_worldSize) {
        m_levelsInWorld[m_currLvl].placePipe();
    }

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

std::string World::displayGrid() {
    std::string result;
    int n = m_levelsInWorld[m_currLvl].getN();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            result += m_levelsInWorld[m_currLvl].getGrid()[i][j];
            result += " ";
        }
       result += "\n";
    }
    return result;
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
    //world.displayGrid();
    return 0;
}
