#include "Monster.h"

Monster::Monster() {
    
}

Monster::Monster(std::string name, int screamPower) {
    m_name = name;
    m_screamPower = screamPower;
}

Monster::~Monster() {

}

bool Monster::screamFight(Monster otherMonster) {
    bool winner = false;
    if (this -> getScream() > otherMonster.getScream()) {
        winner = true;
    }

    return winner;
}

int Monster::getScream() {
    return m_screamPower;
}

std::string Monster::getName() {
    return m_name;
}
