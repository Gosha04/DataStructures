#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster
{
private:
    int m_screamPower;
    std::string m_name;
public:
    Monster();
    Monster(std::string name, int screamPower);
    virtual ~Monster();
    bool screamFight(Monster otherMonster);
    int getScream();
    std::string getName();
};

#endif