#include "World.h"
#include <random>

World::World() :  m_currLvl(0), m_worldSize(2) {
    // generates a world with 2 levels with 5 rows in each
    m_N = 5;
    // creates an array of levels
    m_levelsInWorld = new Level[m_worldSize];
    // loops through all the levels except the last one
     for (int i = 0; i < m_worldSize - 1; ++i) {
        // creates a level with 5 rows and 20% for each variable
        m_levelsInWorld[i] = Level(m_N, 20, 20, 20, 20, 20);
        // places the pipe
        m_levelsInWorld[i].placePipe();
    }
    // generates the last level and does not add a pipe to it
    m_levelsInWorld[m_worldSize-1] = Level(m_N, 20, 20, 20, 20, 20);

    // loops through utill mario is placed
    while (true) {
        // generates two random points within the grid
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        // checks to wee if mario is being placed on the warp pipe or on bowser
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            // if he is not it places pario and breaks out of the loop
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
    // generates a world with the number of levels passed in
    m_N = N;
    m_levelsInWorld = new Level[m_worldSize];
    // loops through all the levels except the last one
     for (int i = 0; i < m_worldSize - 1; ++i) {
        // creates a level with 5 rows and 20% for each variable
        m_levelsInWorld[i] = Level(m_N, x, m, c, g, k);
        // places the pipe
        m_levelsInWorld[i].placePipe();
    }
    // generates the last level and does not add a pipe to it
    m_levelsInWorld[m_worldSize-1] = Level(m_N, x, m, c, g, k);

    // loops through utill mario is placed
    while (true) {
         // generates two random points within the grid
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        // checks to wee if mario is being placed on the warp pipe or on bowser
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            // if he is not it places pario and breaks out of the loop
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
    // deletes the array of the world
    delete[] m_levelsInWorld;
}

// changes the current level that mario is on
void World::nextLevel() {
    // increments the currLev variable
    m_currLvl ++;

    // prints out the current level that mario is on
    m_levelsInWorld[m_currLvl].displayGrid();


    // loops through utill mario is placed
    while (true) {
         // generates two random points within the grid
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        // checks to wee if mario is being placed on the warp pipe or on bowser
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            // if he is not it places pario and breaks out of the loop
            m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        }
        else {
            continue;
        }
    }
}

// shows what will be on the spot that mario will be moving to, to see how to interact
char World::getCurrSpotChar(int x, int y) {
    int row = x;
    int column = y;

    // returns the character in that position
    return m_levelsInWorld[m_currLvl].checkSpot(row, column);

}

void World::displayGrid() {
    // calls the levels display grid method
    m_levelsInWorld[m_currLvl].displayGrid();
}

// returns the current level that mario is on
Level World::getLevel(int index) {
    return m_levelsInWorld[index];
}

// generates a random number within the bounds of the level indecies
int World::randomCoord() {
    int coord = (rand() % m_N);
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
