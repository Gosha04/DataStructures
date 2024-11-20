#include "TournamentTree.h"
#include "TournamentNode.h"
#include <iostream>

TournamentTree::TournamentTree(std::vector<Monster> bracket) {
    m_bracket = bracket;
    createTree(m_bracket);
    populateTree(m_bracket);
    saveTreeAsDot(out_file, finalWinner());
}

TournamentTree::TournamentTree(std::string inFile, std::string outFile, std::string gameType) {
    m_file = inFile;
    out_file = outFile;
    m_type = gameType;
    m_reader.open(m_file);
    std::string name;
    int screamPower;
    while (m_reader >> name >> screamPower) {
        m_bracket.push_back(Monster(name, screamPower));
    }
    createTree(m_bracket); // should be the member bracket
    populateTree(m_bracket);
    if (m_type == "double") {
        doubleElim();
    } else {
        singleElim();
    }
    saveTreeAsDot(out_file, finalWinner());
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
    TournamentTree singleTree(m_file, out_file, "single");
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

// Function to save the tree as a DOT file
void saveTreeAsDot(const std::string& filename, TournamentNode* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}

// Recursive helper function for DOT file generation
void saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID) {
    if (node == NULL) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->getWinner().getName()
         << " (Power: " << node->getWinner().getScream() << ")\"];\n";

    if (node->getLeft()) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->getLeft(), file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->getRight()) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->getRight(), file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}