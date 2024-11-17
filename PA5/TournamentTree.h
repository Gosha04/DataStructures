#include "TournamentNode.h"
#include <fstream>

class TournamentTree
{
private:
    std::vector<Monster> m_primaryBracket;
    std::vector<Monster> m_losersBracket;
    std::ifstream m_reader;
    TournamentNode* m_root;
    int m_bracketSize;
    void createTreeHelper(TournamentNode* root);
    void populateTreeHelper(std::vector<Monster> bracket, TournamentNode* root, int index);
public:
    TournamentTree(std::string file);
    virtual ~TournamentTree();
    void createTree(std::vector<Monster> bracket);
    void populateTree(std::vector<Monster> bracket);
    Monster singleElim(std::string file);
    Monster doubleElim(std::string file);
    Monster finalWinner(Monster first, Monster second);
    void tournamentHelper(TournamentNode* root);
};
