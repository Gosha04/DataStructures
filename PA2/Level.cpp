#include "Level.h"

Level::Level() {
    m_N = 0;
    m_grid = nullptr;
}

Level::Level(int n) {
   this -> MakeGrid(n);
}

Level::~Level() {
    this -> DeleteGrid(m_grid);
}

int Level::GetN() {
    return m_N;
}

void Level::SetN(int n) {
    m_N = n;
}

char** Level::GetGrid() {
    return m_grid;
}

void Level::SetGrid(int n) {
    if (m_grid != nullptr) {
        this -> DeleteGrid(m_grid);
    }
    
    this -> MakeGrid(n);
}

void Level::DeleteGrid(char** grid) {
    for (int i = 0; i < m_N; i++) {
	    delete[] grid[i];
    }
    delete[] grid;
}

void Level::MakeGrid(int n) {
    m_N = n;
    m_grid = new char* [m_N];
    for (int i = 0; i < m_N; ++i) {
        m_grid[i] = new char[m_N];   
    }
}

void Level::DisplayGrid(char** grid) {
    for(int i = 0; i < m_N; ++i) {
        for(int j = 0; j < m_N; ++i) {
            std::cout << m_grid[i][j] << "\n";
        }
    }
}

char Level::CheckSpot(char c) {
    switch (c)
    {
    case 'c':
        m_mario.AddCoin();
        break;
    case 'm':
        m_mario.AddPow();
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
