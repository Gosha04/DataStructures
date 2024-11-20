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
    // populateTree(m_bracket);
}

TournamentTree::~TournamentTree () {
    m_reader.close();
}

void TournamentTree::createTree(std::vector<Monster> bracket) {
    m_bracketSize = (2 * bracket.size()) - 1; // Total nodes in a full binary tree
    int currSize = 0;                         // Track current size of the tree
    int index = 0;
    createTreeHelper(m_root, currSize, 0, m_bracket, index);       // Build the tree
}

void TournamentTree::createTreeHelper(TournamentNode*& root, int& currSize, int currentLvl, std::vector<Monster>& bracket,
int& index) {
    int height = calculateMinHeight(m_bracket.size()); // geeks for geeks
    std::cout << "Height: " << currentLvl << std::endl;
    // Stop recursion if we've created all required nodes
    if (currSize >= m_bracketSize || currentLvl > height) {
        return;
    }

    // Create a new node if it doesn't exist
    if (root == nullptr) {
        root = new TournamentNode();
        ++currSize;
    }


    if (currentLvl == height) {
        root->m_data = bracket[index];
        std::cout << "Populating node with: " << root->m_data.getName() << std::endl;
        ++index;  // Move to the next monster in the bracket
    }

    createTreeHelper(root->m_left, currSize, currentLvl + 1, m_bracket, index);
    createTreeHelper(root->m_right, currSize, currentLvl + 1, m_bracket, index);
}

int TournamentTree::calculateMinHeight (int numLeaves) {
    if (numLeaves <= 0) {
        std::cerr << "Number of leaves must be positive." << std::endl;
        return -1;  // Return an error code for invalid input
    }
    
    // Calculate the height by taking the log base 2 of the number of leaves
    int height = static_cast<int>(std::ceil(std::log2(numLeaves)));
    
    return height;
}



// void TournamentTree::populateTree(std::vector<Monster> bracket) {
//     int index = 0;
//     populateTreeHelper(bracket, m_root, index);
// }

// void TournamentTree::populateTreeHelper(std::vector<Monster> bracket, TournamentNode*& root, int& index) {
//     std::cout << "Index: " << index << std::endl;
//     std::cout << "Bracket thing: " << bracket[index].getName() << std::endl;
//     if (index >= bracket.size()) {
//         return; 
//     }

//     // If the node is a leaf, assign data from the bracket
//     if (root->m_left == nullptr && root->m_right == nullptr) {
//         if (!root->m_hasData) {
//             root->m_data = bracket[index];
//             root->m_hasData = true;
//             std::cout << "Populating node with: " << root->m_data.getName() << std::endl;  // Debug output
//             ++index;  // Move to the next monster
//         }
//     }

//     // Recurse into left and right children to populate the tree
//     populateTreeHelper(bracket, root->m_left, index);
//     populateTreeHelper(bracket, root->m_right, index);
// }


Monster TournamentTree::singleElim() {
    tournamentHelper(m_root);
    return m_root -> m_data;
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

    if (root->m_left != nullptr) {
        std::cout << "Left Node: " << root->m_left->m_data.getName() << std::endl;
    } else {
        std::cout << "Left Node is null" << std::endl;
    }

    if (root->m_right != nullptr) {
        std::cout << "Right Node: " << root->m_right->m_data.getName() << std::endl;
    } else {
        std::cout << "Right Node is null" << std::endl;
    }


    tournamentHelper(root->m_left);
    tournamentHelper(root->m_right);

    if (root -> m_left != nullptr && root -> m_right != nullptr) {
        // std::cout << "Left Node: " << root -> m_left -> m_data.getName() << std::endl;
        // std::cout << "Right Node: " << root -> m_right -> m_data.getName() << std::endl;
        if (root -> m_left -> m_hasData && root -> m_right -> m_hasData) {
            // std::cout << "Left Node: " << root -> m_left -> m_data.getName() << std::endl;
            // std::cout << "Right Node: " << root -> m_right -> m_data.getName() << std::endl;
            m_losersBracket.push_back(root -> fight());
            //std::cout << loser.getName();
        }
    } else if (root -> m_left != nullptr && root -> m_left -> m_hasData) {
        root -> m_data = root -> m_left -> m_data; 
        root -> m_hasData = true;
    }
}

void TournamentTree::printLosers() {
    std::cout << "\n" << m_losersBracket.size();
    for (int i = 0; i < m_losersBracket.size(); ++i) {
        std::cout << m_losersBracket[i].getName() << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    TournamentTree tree("input");
    std::cout << tree.singleElim().getName() << std::endl;
    //tree.printLosers();
    //std::cout << tree.doubleElim().getName();
    return 0;
}
