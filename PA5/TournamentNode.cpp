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
    std::cout << "Fighting: " << m_left->m_data.getName() << " vs " << m_right->m_data.getName() << std::endl;
    if (m_left -> m_data.getScream() == m_right -> m_data.getScream()) {
        m_winner = m_left;
        setData(m_winner->m_data);
        loser = m_right->m_data;
        return loser;
    }
    if (m_right -> m_hasData) {
        if (m_left->m_data.screamFight(m_right->m_data)) {
            m_winner = m_left;
            setData(m_winner->m_data);
            loser = m_right->m_data;
        } else {
            m_winner = m_right;
            loser = m_left->m_data;
        }   
    } else {
        if (m_right == nullptr) {
            m_winner = m_left;
            setData(m_winner -> m_data);
            loser = Monster();
        }
        m_winner = m_left;
        setData(m_winner -> m_data);
        loser = m_right -> m_data;
    }
    std::cout << "Loser: " << loser.getName() << std::endl;
    return loser;
}



void TournamentNode::setData(Monster monster) {
    m_data = monster;
}

// int main(int argc, char const *argv[])
// {
//     Monster meh("Mike", 4);
//     Monster A("A", 1);
//     Monster scarey("Sulley", 10);
//     Monster B("B", 0);

//     TournamentNode* root = new TournamentNode();
//     TournamentNode* rl = new TournamentNode();
//     TournamentNode* rr = new TournamentNode();



//     TournamentNode* l1 = new TournamentNode(meh);
//     TournamentNode* l2 = new TournamentNode(A);
//     TournamentNode* r1 = new TournamentNode(scarey);
//     TournamentNode* r2 = new TournamentNode(B);


//     // switch this back to private after testing
//     root -> m_left = rl;
//     root -> m_right = rr;

//     rl -> m_left = l1;
//     rl -> m_right = l2;

//     rr -> m_left = r1;
//     rr -> m_right = r2;


//     rl->fight();
//     // rl->setData(rl -> m_winner -> m_data);
//     rr->fight();
//     // rr->setData(rr -> m_winner -> m_data);
//     root -> fight();


//     return 0;
// }
