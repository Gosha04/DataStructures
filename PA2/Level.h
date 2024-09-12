#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>
#include <random>
#include "Mario.h"

class Level
{
private:
    int m_N; // grid dimensions
    char** m_grid; // Char array that Mario will traverse on his adventures
    Mario m_mario; // Mario object
    
public:
    Level(); // Def constructor
    Level(int n); // Overloaded constructor
    ~Level(); // Def Destructor
    int getN(); // Getter for N
    void setN(int n); // Setter for N
    char** getGrid(); // Getter for grid
    void deleteGrid(); // Deletes grid
    void makeGrid(int n); // Makes a new grid, useful for new Level
    char checkSpot(char c); // Checks the spot Mario is on and executes a command
    void displayGrid();
    void populateGrid(int x, int m, int c, int g, int k);
    void addPipe();
    void placeMario();
};

#endif