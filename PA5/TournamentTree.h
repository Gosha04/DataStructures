#include "TournamentNode.h"
#include <fstream>

class TournamentTree
{
private:
    std::vector<Monster> m_bracket;
    std::vector<Monster> m_losersBracket;
    std::ifstream m_reader;
    std::string m_file;
    TournamentNode* m_root;
    int m_bracketSize;
    void createTreeHelper(TournamentNode*& root, int& currSize, int currentLvl, std::vector<Monster>& bracket, int& index);
    void populateTreeHelper(std::vector<Monster> bracket, TournamentNode*& root, int& index);
public:
    TournamentTree(std::vector<Monster> bracket);
    TournamentTree(std::string file);
    virtual ~TournamentTree();
    void createTree(std::vector<Monster> bracket);
    void populateTree(std::vector<Monster> bracket);
    Monster singleElim();
    Monster doubleElim();
    Monster finalWinner();
    void printLosers();
    void tournamentHelper(TournamentNode* root);
    int calculateMinHeight(int numLeaves);
};
