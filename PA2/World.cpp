/*
Joshua Vaysman || Dylan Barlava
2449656 || 2428584
vaysman@chapman.edu || dbarlava@chapman.edu
CPSC 350-02
PA2
*/

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
    m_goomba = Enemy(90,1);

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
    m_bowser = Enemy(50,2);
    m_koopa = Enemy(65,1);
    m_goomba = Enemy(80,1);

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
            currSpotChar = m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
            break;
        } else {
            continue;
        }
    }
    // prints out the current level that mario is on
    outFile << "==========\n";
    outFile << m_levelsInWorld[m_currLvl].displayGrid();
    outFile << "==========\n";
    outFile << "Mario placed at (" << m_Hcolumn << "," << m_Hrow << ") on Level: " << m_currLvl + 1 << "\n";

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
    outFile << m_levelsInWorld[m_currLvl].displayGrid();
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
    // calls the battleMath function in level
    // if battleMath returns false mario lost the battle
    if (enemy.battleMath() == false) {
        outFile << "and lost. ";
        int beforeLives = m_mario.getLives();
        // decreases marios power level
        m_mario.decreasePowLevel(enemy.getEnemyPowLevel());
        outFile << "Mario has " << m_mario.getLives() << " lives left." << " Mario is at Power Level " << m_mario.getPowLevel()
        << ". ";
        outFile << "Mario has " << m_mario.getNumCoins() << " coin(s).\n";
        // if mario lost a life, it will reset the number of enemies killed on one life
        if (m_mario.getLives() < beforeLives) {
            m_mario.resetEnemiesKilled();
            }
        return false;
    // if Mario won the battle
    } else {
        outFile << "and won. ";
        outFile << "Mario has " << m_mario.getLives() << " lives left." << " Mario is at Power Level " << m_mario.getPowLevel()
        << ". ";
        outFile << "Mario has " << m_mario.getNumCoins() << " coin(s).\n";
        // increase the number of enemies mario has killed on one life
        m_mario.increaseEnemiesKilled();
        // if mario battled bowser
        if (enemy.equals(m_bowser)) {
            // if he was on the last level
            if (m_currLvl == m_worldSize - 1) {
                outFile << "Mario has saved the princess.\n";
                // send everything left to the output file, close it, and exit the game
                outFile.flush();
                outFile.close();
                exit(0);
            // if he was not on the last level, change to the next level
            } else {
                nextLevel();
            }
        } else {
            m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
        }
        return true;
    }
}

// if mairo lands on the warp pipe it will change the level and place him on the new level
void World::warp() {
    nextLevel();
    currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn); 
    m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
}

// what happens when mario lands on a spot
void World::interact() {
    switch (currSpotChar) {
        // if it is a coin mario will collect it and add to his total
        case 'c':
            outFile << "Mario collected a coin. ";
            m_mario.addCoin();
            outFile << "Mario has " << m_mario.getLives() << " lives left." << " Mario is at Power Level " << m_mario.getPowLevel()
            << ". ";
            outFile << "Mario has " << m_mario.getNumCoins() << " coin(s).\n";
            break;
        // if it is a mushroom mario will increase his power level
        case 'm':
            outFile << "Mario collected a mushroom. ";
            m_mario.addPow();
            outFile << "Mario has " << m_mario.getLives() << " lives left." << " Mario is at Power Level " << m_mario.getPowLevel()
            << ". ";
            outFile << "Mario has " << m_mario.getNumCoins() << " coin(s).\n";
            break;
        // if it is a goomba mario will battle it
        case 'g':
            outFile << "Mario has encountered a Goomba ";
            // if mario loses to the goomba
            if (battle(m_goomba) == false) {
                // if mario lost all his lives it ends the game
                if (m_mario.getLives() <= 0) {
                    outFile << "Mario has lost the game.\n";
                    outFile.flush();
                    outFile.close();
                    exit(0);
                }
                // replace the spot he was on with a goomba since he lost
                m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'g';
            // change the spot to an x since mario won
            } else {
                m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
            }
            break;
        // if it is a koopa mario will battle it
        case 'k':
            outFile << "Mario has encountered a Koopa ";
            // if mario lost to the koopa
            if (battle(m_koopa) == false) {
                // if he lost his last life it will end the game
                if (m_mario.getLives() <= 0) {
                    outFile << "Mario has lost the game.\n";
                    outFile.flush();
                    outFile.close();
                    exit(0);
                }
                // replace the spot with a k since mario did not beat the koops
                m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'k';
            // change the spot to an x if mario won
            } else {
                m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
            }
            break;
        // if it is bowser mario battles him
        case 'b':
            // mario battles bowser until he wins or dies
            while (m_mario.getLives() > 0 && currSpotChar == 'b') {
                outFile << "Mario has encountered Bowser ";
                battle(m_bowser);
                // if mario lost his lives the game is over
                if (m_mario.getLives() <= 0) {
                    outFile << "Mario has lost the game. \n";
                    outFile.flush();
                    outFile.close();
                    exit(0);
                }
            }
            break;
        // if it is a warp pipe mario will warp to the next level
        case 'w':
            outFile << "Mario has found the warp pipe. Mario has moved to the next level!\n";
            warp();
            outFile << "Mario has " << m_mario.getLives() << " lives left." << " Mario is at Power Level " << m_mario.getPowLevel()
            << ". ";
            outFile << "Mario has " << m_mario.getNumCoins() << " coin(s).\n";
            break;
        // if it is nothing mario does nothing
        default:
            outFile << "Mario has found nothing. ";
            outFile << "Mario has " << m_mario.getLives() << " lives left." << " Mario is at Power Level " << m_mario.getPowLevel()
            << ". ";
            outFile << "Mario has " << m_mario.getNumCoins() << " coin(s).\n";
            break;
    }
}

// added move
void World::move() {
    enum Direction { UP = 0, RIGHT, DOWN, LEFT };

    // Generates a random number between 0-3 (inclusive) for direction
    Direction direction = static_cast<Direction>(rand() % 4);
    outFile << "==========\n";
    outFile << "Level: " << m_currLvl + 1 << ". ";
    // Check if Mario is not on an enemy spot
    outFile << "Mario is at position: (" << m_Hcolumn << "," << m_Hrow << ").\n";
    // currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn);
    interact();
    
    // if mario has landed on a spot that is not a koopa or goomba it will change it to an x
    if (currSpotChar != 'k' && currSpotChar != 'g' ) {
        m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
    }

    int newRow = m_Hrow;
    int newColumn = m_Hcolumn;
    
    switch (direction) {
    case UP:
        newRow = (m_Hrow - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved UP.\n";
        outFile << "==========\n";
        break;

    case RIGHT:
        newColumn = (m_Hcolumn + 1) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved RIGHT.\n";
        outFile << "==========\n";
        break;

    case DOWN:
        newRow = (m_Hrow + 1) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved DOWN.\n";
        outFile << "==========\n";
        break;

    case LEFT:
        newColumn = (m_Hcolumn - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
        outFile << "Mario moved LEFT.\n";
        outFile << "==========\n";
        break;
}


    // Update Mario's position
    m_Hrow = newRow;
    m_Hcolumn = newColumn;
    currSpotChar = m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
}


void World::play() {
    int moves = 0;
    while (m_currLvl  <= m_worldSize - 1 && m_mario.getLives() > 0) {
        displayGrid();
        move();
        //displayGrid();

        moves++;
    }
}