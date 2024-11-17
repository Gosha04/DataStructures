#include "TournamentNode.h"

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

Monster TournamentNode::fight() {
    if (m_left-> m_data.screamFight(m_right -> m_data)) {
        m_winner = m_left;
    } else {
        m_winner = m_right;
    }

    return m_winner -> m_data;
}