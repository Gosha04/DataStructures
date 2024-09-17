#include "Level.h"

Level::Level() : m_N(0), m_grid(nullptr) {
    std::srand(time(NULL));

}

Level::Level(int n, int x, int m, int c, int g, int k) {
   this -> makeGrid(n, x, m, c, g, k);
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

void Level::makeGrid(int n, int x, int m, int c, int g, int k) {
    m_N = n;
    m_grid = new char* [m_N];
    for (int i = 0; i < m_N; ++i) {
        m_grid[i] = new char[m_N];   
    }

    populateGrid(x, m, c, g, k);
}

void Level::displayGrid() {
    for(int i = 0; i < m_N; ++i) {
        for(int j = 0; j < m_N; ++j) {
            std::cout << m_grid[i][j];
        }
        std::cout << "\n";
    }
}

char Level::checkSpot(int row, int column) {
    return m_grid[row][column];
    
}

void Level::populateGrid(int x, int m, int c, int g, int k) {
    for(int i = 0; i < m_N; ++i) {
        for(int j = 0; j < m_N; ++j) {
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

void Level::placePipe() {
    int w_row = (rand() % m_N);
    int w_column = (rand() % m_N);

    m_grid[w_row][w_column] = 'w';
}

int* Level::placeMario() {
    int* rowColumn = new int[2];
    int H_row = (rand() % m_N);
    int H_column = (rand() % m_N);

    m_grid[H_row][H_column] = 'H';

    rowColumn[0] = H_row;
    rowColumn[1] = H_column;

    return rowColumn;
}

// int main(int argc, char const *argv[]) {
//     Level level(5);
//     level.populateGrid(4, 20, 26, 25, 25);
//     level.placeMario();
//     level.placePipe();
//     level.displayGrid();

//     std::cout << "Item at position: " << level.checkSpot(3,2) << std::endl;

//     return 0;
// }