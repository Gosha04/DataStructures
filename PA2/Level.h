#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>

class Level
{
private:
    int N;
    char** grid;
    void DeleteGrid(char** grid);
    void MakeGrid(int n);
public:
    Level();
    Level(int n);
    ~Level();
    int GetN();
    void SetN(int n);
    char** GetGrid();
    void SetGrid(int n);
};

#endif