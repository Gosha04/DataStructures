#include "Level.h"

Level::Level() {
    N = 0;
    grid = nullptr;
};

Level::Level(int n) {
   this -> MakeGrid(n);
}

Level::~Level() {
    this -> DeleteGrid(grid);
}

int Level::GetN() {
    return N;
}

void Level::SetN(int n) {
    N = n;
}

char** Level::GetGrid() {
    return grid;
}

void Level::SetGrid(int n) {
    if (grid != nullptr) {
        this -> DeleteGrid(grid);
    }
    
    this -> MakeGrid(n);
}

void Level::DeleteGrid(char** grid) {
    for (int i = 0; i < N; i++) {
	    delete[] grid[i];
    }
    delete[] grid;
}

void Level::MakeGrid(int n) {
    N = n;
    grid = new char* [N];
    for (int i = 0; i < N; ++i) {
        grid[i] = new char[N];   
    }
}
