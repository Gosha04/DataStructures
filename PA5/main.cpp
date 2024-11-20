#include "RunScareGame.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Incorrect usage. Include " << argv[0] << " inputFile outputFile gameType." << endl;
        return 1;
    }

    if (argv[3] != "single" && argv[3] != "double") {
        cout << "Incorrect game type. Use either single or double" << endl;
        return 1;
    }

    RunScareGame* newGame = new RunScareGame(argv[1], argv[2], argv[3]);
    newGame->runTournament();

    delete newGame;
    return 0;
}