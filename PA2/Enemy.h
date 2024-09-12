#ifndef ENEMY_H
#define ENEMY_H

#include "Mario.h"

class Enemy {
public:
    // default constructor
    Enemy();
    // allow user to pass in marios win chance
    Enemy(int marioWinChance);
    // virtual destructor
    virtual ~Enemy();
    // get marios win chance
    int getMarioWinChance();
    // set the chance that mario wins battle agains the enemy
    void setMarioWinChance(int chance);

    int getEnemyPowLevel();
    // return true if mario wins
    bool battle();
private:
    int m_MarioWinChance;
    int m_enemyPowLevel;
};

#endif