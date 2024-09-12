#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>

class Level
{
private:
    int N; // grid dimensions
    char** grid; // Char array that Mario will traverse on his adventures
    void DeleteGrid(char** grid); // Deletes grid
    void MakeGrid(int n); // Makes a new grid, useful for new Level
public:
    Level(); // Def constructor
    Level(int n); // Overloaded constructor
    ~Level(); // Def Destructor
    int GetN(); // Getter for N
    void SetN(int n); // Setter for N
    char** GetGrid(); // Getter for grid
    void SetGrid(int n); // Setter for N
};

#endif