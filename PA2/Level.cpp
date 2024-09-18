#include "Level.h"

// default constructor does not generate a level
Level::Level() : m_N(0), m_grid(nullptr) {
    std::srand(time(NULL));

}

// calls the make grid function
Level::Level(int n, int x, int m, int c, int g, int k) {
   this -> makeGrid(n, x, m, c, g, k);
   std::srand(time(NULL));
}

Level::~Level() {
    // this -> deleteGrid();
}

// returns the number of rows in the grid
int Level::getN() {
    return m_N;
}

// sets the number of rows in the grid
void Level::setN(int n) {
    m_N = n;
}

// returns the grid for the current level
char** Level::getGrid() {
    return m_grid;
}

// void Level::deleteGrid() {
//     for (int i = 0; i < m_N; i++) {
// 	    delete[] m_grid[i];
//     }
//     delete[] m_grid;
// }

// creates the grid and assigns the number of rows
void Level::makeGrid(int n, int x, int m, int c, int g, int k) {
    m_N = n;
    // chreates a 2-d char array
    m_grid = new char* [m_N];
    // assignes each point in the array with a char array
    for (int i = 0; i < m_N; ++i) {
        m_grid[i] = new char[m_N];   
    }
    // populates the grid
    populateGrid(x, m, c, g, k);
}

// displays the grid for the level
void Level::displayGrid() {
    //loops through each row
    for(int i = 0; i < m_N; ++i) {
        // prints out each item in the rows
        for(int j = 0; j < m_N; ++j) {
            std::cout << m_grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// returns what is in a spot on the grid
char Level::checkSpot(int row, int column) {
    return m_grid[row][column];
    
}

// populates the grid with the passed in probabilities
void Level::populateGrid(int x, int m, int c, int g, int k) {
    // loops through the row
    for(int i = 0; i < m_N; ++i) {
        // loops through each item in the row
        for(int j = 0; j < m_N; ++j) {
            // generates a random number
            int number = (rand() % 100) + 1;

            // assigns each position with the correct character based on the number
            if (number <= x)
            {
                m_grid[i][j] = 'x'; // nothing
            } else if (x < number && number <= m + x) {
                m_grid[i][j] = 'm'; // mushroom
            } else if (m + x < number && number <= m + x + c) {
                m_grid[i][j] = 'c'; // coin
            } else if (m + x + c < number && number <= m + x + c + g) {
                m_grid[i][j] = 'g'; // goomba
            } else if ((100 - k) < number && number <= 100) {
                m_grid[i][j] = 'k'; // koopa
            } else {
                std::cout << "Edge Case: " << number << std::endl;
            }
            
        }
    }

    // places the boss on a random position in the grid
    int b_row = (rand() % m_N);
    int b_column = (rand() % m_N);

    m_grid[b_row][b_column] = 'b';
}

//TODO Change this so mario cant start here and doesn't replace boss
void Level::placePipe() {
    // keeps running until a warp pipe is placed
    while (true) {
        // generates two arndom numbers within the correct indecies
        int p_row = rand() % m_N;
        int p_column = rand() % m_N;
        // if the boss is not on the spot it will place the warp pipe
        if (m_grid[p_row][p_column] != 'b') {
            m_grid[p_row][p_column] = 'w';
            break;
        }
        else {  
            continue;
        }
    }
    
}

// places mario on the row and column that were passed in
void Level::placeMario(int row, int column) {
    m_grid[row][column] = 'H';
}

// int main(int argc, char const *argv[]) {
//     Level level(5, 20,20,20,20,20);
//     // level.populateGrid(4, 20, 26, 25, 25);
//     level.placeMario(1,2);
//     level.placePipe();
//     level.displayGrid();

//     std::cout << "Mario at position: " << std::endl;

//     return 0;
// }