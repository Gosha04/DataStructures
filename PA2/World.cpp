#include "World.h"
#include <random>

// default constructor
// generates a world with 2 levels with 5 rows in each
World::World() :  m_currLvl(0), m_worldSize(2), m_goomba(80, 1), m_koopa(65, 1), m_bowser(50, 2), m_mario(1)  {
    // creates an array of levels
    m_levelsInWorld = new Level[m_worldSize];
    // loops through all the levels except the last one
     for (int i = 0; i < m_worldSize - 1; ++i) {
        // creates a level with 5 rows and 20% for each variable
        m_levelsInWorld[i] = Level(5, 20, 20, 20, 20, 20);
        // places the pipe
        m_levelsInWorld[i].placePipe();
    }
    // generates the last level and does not add a pipe to it
    m_levelsInWorld[m_worldSize-1] = Level(5, 20, 20, 20, 20, 20);

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

// generates a world with the number of levels passed in
World::World(int L, int N,int life, int x, int m, int c, int g, int k) : m_currLvl(0), m_worldSize(L), 
m_goomba(80, 1), m_koopa(65, 1), m_bowser(50, 2), m_mario(life) {
    m_levelsInWorld = new Level[m_worldSize];
    // loops through all the levels except the last one
     for (int i = 0; i < m_worldSize - 1; ++i) {
        // creates a level with 5 rows and 20% for each variable
        m_levelsInWorld[i] = Level(N, x, m, c, g, k);
        // places the pipe
        m_levelsInWorld[i].placePipe();
    }
    // generates the last level and does not add a pipe to it
    m_levelsInWorld[m_worldSize-1] = Level(N, x, m, c, g, k);

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

    // currSpotChar = getCurrSpotChar(currSpot);
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
    int coord = (rand() % m_levelsInWorld[0].getN());
    return coord;
}

void World::battle(Enemy enemy) {
    if (enemy.battleMath() == false) {
        if (m_mario.getPowLevel() == 0) {
            m_mario.resetEnemiesKilled();
            }
        m_mario.decreasePowLevel(m_goomba.getEnemyPowLevel());
        } else {
            m_mario.increaseEnemiesKilled();
            if (enemy.equals(m_bowser)) {
                warp();
            }
        }
}

void World::warp() {
    currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn); 
}

void World::interact() {
    switch (currSpotChar) {
        case 'c':
            m_mario.addCoin();
            break;
        case 'm':
            m_mario.addPow();
            break;
        case 'g':
            battle(m_goomba);
            // Movement
            break;
        case 'k':
            battle(m_koopa);
            // Movement
            break;
        case 'b':
            battle(m_bowser);
            // Warp
            break;
        case 'w':
            warp();
            break;
        default:
            break;
    }
}

// added move
void World::move() {
    m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
    int newRow = m_Hrow;
    int newColumn = m_Hcolumn;

    // generates a random number between 0-3
    int direction = (rand() % 4);
    
    switch (direction) {
    // Move up
    case 0:
        newRow = (m_Hrow - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
        std::cout << "Mario moved up" << std::endl;
        break;
    
    // Move right
    case 1:
        newColumn = (m_Hcolumn + 1) % m_levelsInWorld[m_currLvl].getN();
        std::cout << "Mario moved right" << std::endl;
        break;
    
    // Move down
    case 2:
        newRow = (m_Hrow + 1) % m_levelsInWorld[m_currLvl].getN();
        std::cout << "Mario moved down" << std::endl;
        break;
    
    // Move left
    case 3:
        newColumn = (m_Hcolumn - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
        std::cout << "Mario moved left" << std::endl;
        break;
    }

    // Update Mario's position
    m_Hrow = newRow;
    m_Hcolumn = newColumn;
    m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
}

int getM_Hcolumn();

int main(int argc, char const *argv[])
{
    std::cout << "Test";
    World world(3, 5, 3, 20, 20, 20, 20, 20);
    std::cout << "Grid pointer: " << world.getLevel(0).getGrid() << std::endl;
    std::cout << "Test2\n";
    
    world.displayGrid();

    world.move();

    world.displayGrid();

    world.move();

    world.displayGrid();

    //world.move();
    return 0;
}
