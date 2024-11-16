#include "Monster.h"

class TournamentNode
{
private:
    TournamentNode* m_winner;
    TournamentNode* m_left;
    TournamentNode* m_right;
    Monster m_data;
    bool m_hasData;
    friend class TournamentTree;
public:
    TournamentNode();
    TournamentNode(Monster monster);
    virtual ~TournamentNode();
    void fight();
};
