#include "World.h"

World::World() :  m_currLvl(0), m_worldSize(0), m_level(0) {
    
}

World::World(int L, int N) : m_currLvl(0), m_worldSize(L), m_level(N) {

}

World::~World() {

}

char World::nextLevel() {
    m_level.populateGrid(4, 20, 26, 25, 25);

    if (m_currLvl == m_worldSize) {
        m_level.placePipe();
    }

    m_currLvl ++;

    return m_level.placeMario();
}