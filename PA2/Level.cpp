#include "Level.h"

Level::Level() {
    m_N = 0;
    m_grid = nullptr;
    std::srand(time(NULL));

}

Level::Level(int n) {
   this -> makeGrid(n);
   std::srand(time(NULL));
}

Level::~Level() {
    this -> deleteGrid();
}

int Level::getN() {
    return m_N;
}

void Level::setN(int n) {
    m_N = n;
}

char** Level::getGrid() {
    return m_grid;
}

void Level::deleteGrid() {
    for (int i = 0; i < m_N; i++) {
	    delete[] m_grid[i];
    }
    delete[] m_grid;
}

void Level::makeGrid(int n) {
    m_N = n;
    m_grid = new char* [m_N];
    for (int i = 0; i < m_N; ++i) {
        m_grid[i] = new char[m_N];   
    }
}

void Level::displayGrid() {
    for(int i = 0; i < m_N; ++i) {
        for(int j = 0; j < m_N; ++i) {
            std::cout << m_grid[i][j];
        }
        std::cout << "\n";
    }
}

void Level::checkSpot(char c) {
    switch (c)
    {
    case 'c':
        m_mario.addCoin();
        break;
    case 'm':
        m_mario.addPow();
        break;
    case 'g':
        //TODO goomba.fight();
        break;
    case 'k':
        //TODO koopa.fight();
    case 'b':
        //TODO boss.fight();
        break;
    case 'w':
        //TODO world.warp();
    default:
        break;
    }
}

void Level::populateGrid(int x, int m, int c, int g, int k) {
    for(int i = 0; i < m_N; ++i) {
        for(int j = 0; j < m_N; ++i) {
            int number = (rand() % 100) + 1;

            if (number <= x)
            {
                m_grid[i][j] = 'x';
            } else if (x < number && number <= m + x) {
                m_grid[i][j] = 'm';
            } else if (m + x < number && number <= m + x + c) {
                m_grid[i][j] = 'c';
            } else if (m + x + c < number && number <= m + x + c + g) {
                m_grid[i][j] = 'g';
            } else if ((100 - k) < number && number <= 100) {
                m_grid[i][j] = 'k';
            } else {
                std::cout << "Edge Case: " << number << std::endl;
            }
            
        }
    }

    int b_row = (rand() % m_N);
    int b_column = (rand() % m_N);

    m_grid[b_row][b_column] = 'b';
}

void Level::addPipe() {
    int w_row = (rand() % m_N);
    int w_column = (rand() % m_N);

    m_grid[w_row][w_column] = 'w';
}

void Level::placeMario() {
    int H_row = (rand() % m_N);
    int H_column = (rand() % m_N);

    m_grid[H_row][H_column] = 'H';
}

int main(int argc, char const *argv[])
{
    Level level(5);
    level.populateGrid(20, 15, 15, 30, 20);
    level.displayGrid();

    return 0;
}
