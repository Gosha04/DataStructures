#include "TournamentNode.h"
#include <fstream>

class TournamentTree
{
private:
    std::vector<Monster> m_bracket;
    std::vector<Monster> m_losersBracket;
    std::ifstream m_reader;
    std::string m_file;
    std::string out_file;
    std::string m_type;
    TournamentNode* m_root;
    int m_bracketSize;
    void createTreeHelper(TournamentNode* root);
    void populateTreeHelper(std::vector<Monster> bracket, TournamentNode* root, int index);
public:
    TournamentTree(std::vector<Monster> bracket);
    TournamentTree(std::string inFile, std::string outFile, std::string gameType);
    virtual ~TournamentTree();
    void createTree(std::vector<Monster> bracket);
    void populateTree(std::vector<Monster> bracket);
    Monster singleElim();
    Monster doubleElim();
    Monster finalWinner();
    void tournamentHelper(TournamentNode* root);
    void saveTreeAsDot(const std::string& filename, TournamentNode* rootNode);
    void saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID);
};