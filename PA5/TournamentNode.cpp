#include "TournamentNode.h"
#include <iostream>

TournamentNode::TournamentNode() {
    m_data = Monster();
    m_winner = NULL;
    m_left = NULL;
    m_right = NULL;
}

TournamentNode::TournamentNode(Monster monster) {
    m_data = monster;
    m_winner = NULL;
    m_left = NULL;
    m_right = NULL;
}

TournamentNode::~TournamentNode() {
    
}


// seg faults if it is a by
// don't think we need to worry about it as I assigned by's manually in TournamentTree
Monster TournamentNode::fight() {
    Monster loser;
    if (m_left-> m_data.screamFight(m_right -> m_data)) {
        m_winner = m_left;
        loser = m_right -> m_data;
    } else {
        m_winner = m_right;
        loser = m_left -> m_data;
    }

    return loser;
}

int main(int argc, char const *argv[])
{
    Monster meh("Mike", 4);
    Monster scarey("Sulley", 10);

    TournamentNode* root = new TournamentNode();

    TournamentNode* left = new TournamentNode(meh);
    TournamentNode* right = new TournamentNode(scarey);

    // switch this back to private after testing
    root -> m_left = left;
    root -> m_right = right;

    std::cout << root->fight().getName() << std::endl;

    return 0;
}
