#include "TournamentTree.h"

TournamentTree::TournamentTree(std::string file) {
    m_reader.open(file);
    std::string name;
    int screamPower;
    while (m_reader >> name >> screamPower) {
        m_primaryBracket.push_back(Monster(name, screamPower));
    }
}

void TournamentTree::createTree(std::vector<Monster> bracket) {
    m_bracketSize = (2 * bracket.size()) - 1;
    createTreeHelper(m_root);
}

void TournamentTree::createTreeHelper(TournamentNode* root) {
    int currSize = 0;
    while (currSize < m_bracketSize) {
        if (root == NULL){ 
            root = new TournamentNode();
            ++currSize;
        } else if (root -> m_left == NULL) {
            createTreeHelper(root -> m_left);
            ++currSize;
        } else {
            createTreeHelper(root -> m_right);
            ++currSize;
        }
    }
}

void TournamentTree::populateTree(std::vector<Monster> bracket) {
    int index = 0;
    populateTreeHelper(bracket, m_root, index);
}

void TournamentTree::populateTreeHelper(std::vector<Monster> bracket, TournamentNode* root, int index) {
    if (root == nullptr || index >= bracket.size()) {
        return; 
    }

    if (root->m_left == nullptr && root->m_right == nullptr) {
        if (!root -> m_hasData) { 
            root -> m_data = bracket[index];
            root -> m_hasData = true;      
            ++index;                       
        }
        return;
    }

    // Recursive case: Traverse left and right subtrees
    populateTreeHelper(bracket, root->m_left, index);
    populateTreeHelper(bracket, root->m_right, index);
}