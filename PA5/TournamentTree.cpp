#include "TournamentTree.h"
#include <iostream>
#include <cmath>

TournamentTree::TournamentTree(std::vector<Monster> bracket) {
    m_bracket = bracket;
    m_root = nullptr;
    createTree(m_bracket);
    // populateTree(m_bracket);
}

TournamentTree::TournamentTree(std::string file) {
    m_file = file;
    m_root = nullptr;
    m_reader.open(m_file);
    std::string name;
    int screamPower;
    while (m_reader >> name >> screamPower) {
        m_bracket.push_back(Monster(name, screamPower));
        std::cout<< m_bracket.size()<< std::endl;
    } 
    createTree(m_bracket); // should be the member bracket
}

TournamentTree::~TournamentTree () {
    m_reader.close();
}

void TournamentTree::createTree(std::vector<Monster> bracket) {
    while ((bracket.size() & (bracket.size() - 1)) != 0) {
        bracket.push_back(Monster("BYE", -1)); // Add a placeholder "BYE" monster
    }

    std::cout << bracket.size() << std::endl;

    m_bracketSize = (2 * bracket.size()) - 1; // Total nodes in a full binary tree
    int currSize = 0;                         // Track current size of the tree
    int index = 0;
    createTreeHelper(m_root, currSize, 0, bracket, index);       // Build the tree
}

void TournamentTree::createTreeHelper(TournamentNode*& root, int& currSize, int currentLvl, std::vector<Monster>& bracket,
int& index) {
    int height = calculateMinHeight(bracket.size()); // geeks for geeks
    std::cout << "Level: " << currentLvl << std::endl;
    // Stop recursion if we've created all required nodes
    if (currSize > m_bracketSize || currentLvl > height) {
        return;
    }

    if (root == nullptr) {
        root = new TournamentNode();
        root -> m_hasData = false;
        ++currSize;
    }


    if (currentLvl == height - 1) {
        if (index >= m_bracketSize - 2) {
            root->m_data = bracket[index];
            root->m_hasData = true;
            std::cout << "Populating node with: " << root->m_data.getName() << std::endl;
            ++index;
        }
    } else if (currentLvl == height) {
        root->m_data = bracket[index];
        root->m_hasData = true;
        std::cout << "Populating node with: " << root->m_data.getName() << std::endl;
        ++index;
    }

    createTreeHelper(root->m_left, currSize, currentLvl + 1, bracket, index);
    createTreeHelper(root->m_right, currSize, currentLvl + 1, bracket, index);
}

int TournamentTree::calculateMinHeight (int numLeaves) {
    if (numLeaves <= 0) {
        return -1; 
    }
    
    // Calculate the height by taking the log base 2 of the number of leaves
    int height = std::ceil(std::log2(numLeaves));
    
    return height;
}

Monster TournamentTree::singleElim() {
    tournamentHelper(m_root);
    return m_root -> m_data;
}

Monster TournamentTree::doubleElim() {
    int i = 0;
    while (i < m_losersBracket.size()) {
        if (m_losersBracket[i].getName() == "BYE" || m_losersBracket[i].getName() == "") {
            m_losersBracket.erase(m_losersBracket.begin() + i);
        } else {
            ++i; 
        }
    }
    printLosers();
    tournamentHelper(m_root);
    return m_root -> m_data;
}

Monster TournamentTree::finalWinner() {
    m_finals.push_back(singleElim());
    // printLosers();
    m_finals.push_back(doubleElim());
    if (m_finals[0].screamFight(m_finals[1])) {
        return m_finals[0];
    } else {
        return m_finals[1];
    }
}

void TournamentTree::tournamentHelper(TournamentNode* root) {
    std::cout << "CURRENT NODE: " << root -> m_data.getName() << std::endl;
    if (root -> m_left == nullptr && root -> m_right == nullptr) {
        return;
    }  

    if (root->m_left != nullptr) {
        std::cout << "Left Node: " << root->m_left->m_data.getName() << std::endl;
    } 

    if (root->m_right != nullptr) {
        std::cout << "Right Node: " << root->m_right->m_data.getName() << std::endl;
    } 

    std::cout << "Go Left" << std::endl;
    tournamentHelper(root->m_left);
    if (root -> m_right != nullptr) {
        std::cout << "Go Right" << std::endl;
        tournamentHelper(root->m_right);
    }

    if (root -> m_left && root -> m_right) {
        m_losersBracket.push_back(root -> fight());
    }
}

void TournamentTree::printLosers() {
    std::cout << "\nLOSER Size: " << m_losersBracket.size() << std::endl;
    for (int i = 0; i < m_losersBracket.size(); ++i) {
        std::cout << m_losersBracket[i].getName() << std::endl;
    }
}
