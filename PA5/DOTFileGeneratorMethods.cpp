#include "TournamentTree.h"
#include <iostream>
#include <fstream>

/*
You will use these methods in your code to save your winner and/ or loser bracket trees as DOT files
Then, you'll be able to visualize your trees at this link: https://dreampuf.github.io/GraphvizOnline/
*/

// Recursive helper function for DOT file generation
void saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID) {
    if (node == NULL) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node-> m_data.getName()
         << " (Power: " << node->m_data.getScream() << ")\"];\n";

    if (node->m_left) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->m_left, file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->m_right) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->m_right, file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
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

int main(int argc, char const *argv[])
{
    TournamentTree tree("input");
    tree.singleElim();
    TournamentTree doubleTree(tree.m_losersBracket);
    // tree.printLosers();
    doubleTree.doubleElim();
    // std::cout << "\n" << tree.finalWinner().getName() << std::endl;

    saveTreeAsDot("output", tree.m_root);
    saveTreeAsDot("doubleOut", doubleTree.m_root);

    return 0;
}



