#include "RunScareGame.h"
#include "TournamentTree.h"
#include <iostream>

RunScareGame::RunScareGame(std::string inputFile, std::string outputFile, std::string gameType) {
    m_input = inputFile;
    m_output = outputFile;
    m_type = gameType; // can be single or double
}

RunScareGame::RunScareGame() {
    m_input = "input.txt";
    m_output = "output.dot";
    m_type = "single";
}

RunScareGame::~RunScareGame() {

}

void RunScareGame::runTournament() {
    TournamentTree* doubleElimGame = new TournamentTree(m_input, m_output, m_type);
}