#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>
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
    int GetN(); // Getter for N
    void SetN(int n); // Setter for N
    char** GetGrid(); // Getter for grid
    void SetGrid(int n); // Setter for N
    void DeleteGrid(char** grid); // Deletes grid
    void MakeGrid(int n); // Makes a new grid, useful for new Level
    char CheckSpot(char c); // Checks the spot Mario is on and executes a command
    void DisplayGrid(char** grid);
};

#endif