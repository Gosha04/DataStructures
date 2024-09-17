#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>
#include <random>

class Level
{
private:
    int m_N; // grid dimensions
    char** m_grid; // Char array that Mario will traverse on his adventures
    
public:
    Level(); // Def constructor
    Level(int n, int x, int m, int c, int g, int k); // Overloaded constructor
    ~Level(); // Def Destructor
    int getN(); // Getter for N
    void setN(int n); // Setter for N
    char** getGrid(); // Getter for grid
    void deleteGrid(); // Deletes grid
    void makeGrid(int n, int x, int m, int c, int g, int k); // Makes a new grid, useful for new Level
    char checkSpot(int row, int column); // Checks the spot Mario is on and returns what is on that blocks
    void displayGrid(); // Displays the grid in char form
    void populateGrid(int x, int m, int c, int g, int k); // Populates each square of the level with a character
    void placePipe(int row, int column); // Adds a warp pipe to the level
    void placeMario(int row, int column); // Places Mario onto the grid
};

#endif