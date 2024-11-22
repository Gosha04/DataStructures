#include "TournamentNode.h"
#include <fstream>

class TournamentTree
{
private:
    std::vector<Monster> m_bracket;
    std::ifstream m_reader;
    std::string m_file;
    int m_bracketSize;
    void createTreeHelper(TournamentNode*& root, int& currSize, int currentLvl, std::vector<Monster>& bracket, int& index);
    void tournamentHelper(TournamentNode* root);

public:
    TournamentTree();
    std::vector<Monster> m_finals;
    std::vector<Monster> m_losersBracket;
    TournamentNode* m_root;
    TournamentTree(std::vector<Monster> bracket);
    TournamentTree(std::string file);
    virtual ~TournamentTree();
    void createTree(std::vector<Monster> bracket);
    Monster singleElim();
    Monster doubleElim();
    Monster finalWinner();
    void printLosers();
    int calculateMinHeight(int numLeaves);
};
