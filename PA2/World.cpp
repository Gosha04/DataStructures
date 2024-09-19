#include "World.h"
#include <iostream>
using namespace std;

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

    // generate the mario and enemy objects
    m_mario = Mario();
    m_bowser = Enemy(50,2);
    m_koopa = Enemy(65,1);
    m_goomba = Enemy(80,1);

    // loops through until mario is placed
    while (true) {
        // generates two random points within the grid
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn);
        // checks to see if mario is being placed on the warp pipe or on bowser
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
    // creates the outputfile and opens it
    outFile.open("log.txt");

    srand(time(NULL));
}

// generates a world with the number of levels passed in
World::World(int L, int N,int life, int x, int m, int c, int g, int k, std::string output) : m_currLvl(0), m_worldSize(L), 
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

    // Generate the mario and enemy objects
    m_mario = Mario(life);
    m_bowser = Enemy(40,2);
    m_koopa = Enemy(90,1);
    m_goomba = Enemy(90,1);

    // loops through utill mario is placed
    while (true) {
         // generates two random points within the grid
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
        // checks to wee if mario is being placed on the warp pipe or on bowser
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            // if he is not it places mario and breaks out of the loop
            currSpotChar = m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        }
        else {
            continue;
        }
    }

    // creates the outputfile and opens it
    outFile.open(output);

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

    // loops through until mario is placed
    while (true) {
         // generates two random points within the grid
        m_Hrow = randomCoord();
        m_Hcolumn = randomCoord();
      
        // checks to see if mario is being placed on the warp pipe or on bowser
        if ((m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'b') && 
        (m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] != 'w')) {
            // if he is not it places mario and breaks out of the loop
            m_levelsInWorld[m_currLvl].displayGrid();
            std::cout <<"\n\n\n\n";
            currSpotChar = m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        } else {
            continue;
        }
    }
    // prints out the current level that mario is on
    m_levelsInWorld[m_currLvl].displayGrid();
    std::cout << "Mario placed at (" << m_Hrow << ", " << m_Hcolumn << ") on level " << m_currLvl << std::endl;

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

bool World::battle(Enemy enemy) {
    if (enemy.battleMath() == false) {
        int beforeLives = m_mario.getLives();
        m_mario.decreasePowLevel(enemy.getEnemyPowLevel());
        outFile << "Lives: " << m_mario.getLives() << " PowLvl: " << m_mario.getPowLevel() << " Lose\n";
        if (m_mario.getLives() < beforeLives) {
            m_mario.resetEnemiesKilled();
            }
        return false;
        } else {
            outFile << "Lives: " << m_mario.getLives() << " PowLvl: " << m_mario.getPowLevel() << " Win\n";
            m_mario.increaseEnemiesKilled();
            if (enemy.equals(m_bowser)) {
                if (m_currLvl == m_worldSize - 1) {
                std::cout << "Game Over!" << std::endl;
                outFile.flush();
                exit(0);
                } else {
                    nextLevel();
                }
            } else {
                m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
            }
            return true;
        }
}

void World::warp() {
    nextLevel();
    currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn); 
    m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
    std::cout << "Mario warped!\n";
    outFile << "Mario warped!\n";
}

void World::interact() {
    switch (currSpotChar) {
        case 'c':
            outFile << "Coin\n";
            m_mario.addCoin();
            break;
        case 'm':
            outFile << "Mushroom\n";
            m_mario.addPow();
            break;
        case 'g':
            outFile << "Goomba\n";
            battle(m_goomba);
            // Movement
            break;
        case 'k':
            outFile << "Koopa\n";
            battle(m_koopa);
            // Movement
            break;
        case 'b':
            outFile << "Boss\n";
            while (m_mario.getLives() > 0 && currSpotChar == 'b') {
                cout << "here" << endl;
                battle(m_bowser);
                if (m_mario.getLives() <= 0) {
                    outFile.flush();
                    exit(0);
                }
            }
            // Warp
            break;
        case 'w':
            outFile << "Pipe\n";
            warp();
            break;
        default:
            outFile << "Encountered Edge Case " << currSpotChar << " \n";
            break;
    }
}

// added move
void World::move() {
    enum Direction { UP = 0, RIGHT, DOWN, LEFT };

    // Generates a random number between 0-3 (inclusive) for direction
    Direction direction = static_cast<Direction>(rand() % 4);

    // Check if Mario is not on an enemy spot
    outFile << "Start spot character: '" << currSpotChar << "'\n";
    // currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn);
    interact();
    
    if (currSpotChar == 'k') {
        outFile << "Mario found a KOOPA!\n";
        m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'k';
    } else if (currSpotChar == 'g') {
        outFile << "Mario found a GOOMBA!\n";
        m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'g';
    } else if (currSpotChar == 'H') {
        m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'x';
        outFile << "Mario on himself\n";
    } else {
        outFile << "Mario did not encounter an enemy\n";
        m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
    }

    int newRow = m_Hrow;
    int newColumn = m_Hcolumn;
    
    switch (direction) {
    case UP:
        newRow = (m_Hrow - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
        
        outFile << "Mario moved up\n";
        std::cout << "Mario moved up\n";  // Print to console
        break;

    case RIGHT:
        newColumn = (m_Hcolumn + 1) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved right\n";
        std::cout << "Mario moved right\n";  // Print to console
        break;

    case DOWN:
        newRow = (m_Hrow + 1) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved down\n";
        std::cout << "Mario moved down\n";  // Print to console
        break;

    case LEFT:
        newColumn = (m_Hcolumn - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved left\n";
        std::cout << "Mario moved left\n";  // Print to console
        break;
}


    // Update Mario's position
    m_Hrow = newRow;
    m_Hcolumn = newColumn;
    currSpotChar = m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
    outFile << "Current spot character at end of move: '" << currSpotChar << "'\n";
}


void World::play() {
    outFile << "Current Character " << currSpotChar << " \n";
    int moves = 0;
    while (m_currLvl  <= m_worldSize - 1 && m_mario.getLives() > 0) {
        displayGrid();
        std::cout << "Test\n";
        outFile << "Test\n";
        move();
        std::cout << "Test\n";
        outFile << "Test\n";
        //displayGrid();

        moves++;
        std::cout << "CURRENT LIVES: " << m_mario.getLives() << "\n\n\n";
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "Test\n";
    World world(3, 5, 3, 20, 20, 20, 20, 20, "MarioLog.txt");
    // std::cout << "Grid pointer: " << world.getLevel(0).getGrid() << std::endl;
    // std::cout << "Test2\n";
    
    world.play();

    return 0;
}
