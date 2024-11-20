#include "TournamentTree.h"

TournamentTree::TournamentTree(std::vector<Monster> bracket) {
    m_bracket = bracket;
    createTree(m_bracket);
    populateTree(m_bracket);
}

TournamentTree::TournamentTree(std::string file) {
    m_file = file;
    m_reader.open(m_file);
    std::string name;
    int screamPower;
    while (m_reader >> name >> screamPower) {
        m_bracket.push_back(Monster(name, screamPower));
    }
    createTree(m_bracket); // should be the member bracket
    populateTree(m_bracket);
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

    populateTreeHelper(bracket, root->m_left, index);
    populateTreeHelper(bracket, root->m_right, index);
}

Monster TournamentTree::singleElim() {
    TournamentTree singleTree(m_file);
    tournamentHelper(singleTree.m_root);
    return singleTree.m_root -> m_data;
}

Monster TournamentTree::doubleElim() {
    TournamentTree doubleTree(m_losersBracket);
    tournamentHelper(doubleTree.m_root);
    return doubleTree.m_root -> m_data;
}

Monster TournamentTree::finalWinner() {
    Monster first = singleElim();
    Monster second = doubleElim();
    if (first.screamFight(second)) {
        return first;
    } else {
        return second;
    }
}

void TournamentTree::tournamentHelper(TournamentNode* root) {
    if (root == nullptr) {
        return;
    }  

    tournamentHelper(root->m_left);
    tournamentHelper(root->m_right);
  

    if (root -> m_left != nullptr && root -> m_right != nullptr) {
        if (root -> m_left -> m_hasData && root -> m_right -> m_hasData) {
            Monster loser = root -> fight(); 
            m_losersBracket.push_back(loser);
        }
    } else if (root -> m_left != nullptr && root -> m_left -> m_hasData) {
        root -> m_data = root -> m_left -> m_data; 
        root -> m_hasData = true;
    }
}