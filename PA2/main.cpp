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
    int L;
    int N;
    int V;
    int coin;
    int nothing;
    int goomba;
    int koopa;
    int mushroom;

    std::ifstream inFile;
    inFile.open(argv[1]);

    std::string fileName = argv[2];

    std::string line;
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

    World world(L,N,V,nothing,mushroom,coin,goomba,koopa, fileName); // add in the ofstream in the world constructors and pass in the name of the file
    world.play();
}