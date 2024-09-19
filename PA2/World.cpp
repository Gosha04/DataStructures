#include "World.h"

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

bool World::battle(Enemy enemy) {
    if (enemy.battleMath() == false) {
        std::cout << "Lives: " << m_mario.getLives() << " Lose";
        if (m_mario.getPowLevel() == 0) {
            m_mario.resetEnemiesKilled();
            }
        return 1;
        m_mario.decreasePowLevel(m_goomba.getEnemyPowLevel());
        } else {
            std::cout << "Lives: " << m_mario.getLives() << " Win";
            m_mario.increaseEnemiesKilled();
            if (enemy.equals(m_bowser)) {
                warp();
            } else {
                m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
            }
            return 0;
        }
}

void World::warp() {
    nextLevel();
    currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn); 
    m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
    std::cout << "Mario warped!\n";
}

void World::interact() {
    switch (currSpotChar) {
        case 'c':
            std::cout << "Coin";
            m_mario.addCoin();
            break;
        case 'm':
            std::cout << "Mushroom";
            m_mario.addPow();
            break;
        case 'g':
            std::cout << "Goomba";
            battle(m_goomba);
            // Movement
            break;
        case 'k':
            std::cout << "Koopa";
            battle(m_koopa);
            // Movement
            break;
        case 'b':
            std::cout << "Boss";
            while (m_mario.getLives() > 0 && battle(m_bowser) == 0) {
                continue;
            }
            // Warp
            break;
        case 'w':
            std::cout << "Pipe";
            warp();
            break;
        default:
            std::cout << "Encountered Edge Case " << currSpotChar << " \n";
            break;
    }
}

// added move
void World::move() {
    interact();
    enum Direction { UP = 0, RIGHT, DOWN, LEFT };

    // Generates a random number between 0-3 (inclusive) for direction
    Direction direction = static_cast<Direction>(rand() % 4);

    // Check if Mario is not on an enemy spot
    currSpotChar = getCurrSpotChar(m_Hrow, m_Hcolumn);
    if (currSpotChar == 'k') {
        std::cout << "Mario found a KOOPA!\n";
        m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'k';
    } else if (currSpotChar == 'g') {
        std::cout << "Mario found a GOOMBA!\n";
        m_levelsInWorld[m_currLvl].getGrid()[m_Hrow][m_Hcolumn] = 'g';
    } else {
        std::cout << "Mario did not encounter an enemy\n";
        m_levelsInWorld[m_currLvl].clearSpot(m_Hrow, m_Hcolumn);
    }

    int newRow = m_Hrow;
    int newColumn = m_Hcolumn;
    
    switch (direction) {
        case UP:
            newRow = (m_Hrow - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
            std::cout << "Mario moved up" << std::endl;
            break;

        case RIGHT:
            newColumn = (m_Hcolumn + 1) % m_levelsInWorld[m_currLvl].getN();
            std::cout << "Mario moved right" << std::endl;
            break;

        case DOWN:
            newRow = (m_Hrow + 1) % m_levelsInWorld[m_currLvl].getN();
            std::cout << "Mario moved down" << std::endl;
            break;

        case LEFT:
            newColumn = (m_Hcolumn - 1 + m_levelsInWorld[m_currLvl].getN()) % m_levelsInWorld[m_currLvl].getN();
            std::cout << "Mario moved left" << std::endl;
            break;
    }

    // Update Mario's position
    m_Hrow = newRow;
    m_Hcolumn = newColumn;
    m_levelsInWorld[m_currLvl].placeMario(m_Hrow, m_Hcolumn);
}


void World::play() {
    std::cout << "Current Character" << currSpotChar << " \n";
    int moves = 0;
    interact();
    while (m_mario.getLives() > 0 && m_currLvl <= m_worldSize && moves < 2) {
        std::cout << "Test\n";
        displayGrid();
        move();
        displayGrid();
        std::cout << "Test\n";
        moves++;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "Test";
    World world(3, 5, 3, 20, 20, 20, 20, 20);
    // std::cout << "Grid pointer: " << world.getLevel(0).getGrid() << std::endl;
    // std::cout << "Test2\n";
    
    world.play();

    // world.displayGrid();

    // world.move();

    // std::cout << "Test1\n";

    // world.displayGrid();

    // world.move();

    // std::cout << "Test2\n";

    // world.displayGrid();

    // std::cout << "Test2.5\n";

    // world.warp();

    // std::cout << "Test3\n";

    // world.displayGrid();

    return 0;
}
