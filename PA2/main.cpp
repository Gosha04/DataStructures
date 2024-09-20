#include <iostream>
#include <fstream>
#include "World.h"

int main(int argc, char** argv) {
    // throws an error if there isnt the input and output file names
    if (argc != 3) {
        std::cout << "Wrong number of command line arguments" << std::endl;
        return 1;
    }

    // creates all the variables that are needed for world
    int L; // levels
    int N; // number of rows
    int V; // number of lives
    int coin; // %coin
    int nothing; // %nothing
    int goomba; // %goomba
    int koopa; // %koopa
    int mushroom; // %mushroom

    // opens the input stream to get all the variables
    std::ifstream inFile;
    inFile.open(argv[1]);

    // assigns a string with the output files name
    std::string fileName = argv[2];

    std::string line;
    // reads in all the variables
    getline(inFile,line);
    L = atoi(line.c_str());

    getline(inFile,line);
    N = atoi(line.c_str());

    getline(inFile,line);
    V = atoi(line.c_str());

    getline(inFile,line);
    coin = atoi(line.c_str());

    getline(inFile,line);
    nothing = atoi(line.c_str());

    getline(inFile,line);
    goomba = atoi(line.c_str());

    getline(inFile,line);
    koopa = atoi(line.c_str());

    getline(inFile,line);
    mushroom = atoi(line.c_str());

    //close the input file since it is done being read from
    inFile.close();

    // creates the world with all the input variables and the output files name
    World world(L,N,V,nothing,mushroom,coin,goomba,koopa, fileName);
    // calls the worlds play function to start the game
    world.play();
}