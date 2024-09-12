#ifndef ENEMY_H
#define ENEMY_H

#include "Mario.h"

class Enemy {
public:
    // default constructor
    Enemy();
    // allow user to pass in marios win chance
    Enemy(int marioWinChance, Mario mario);
    // virtual destructor
    virtual ~Enemy();
    // get marios win chance
    virtual int GetMarioWinChance();
    // set the chance that mario wins battle agains the enemy
    virtual void SetMarioWinChance(int chance);
    // return true if mario wins
    virtual bool Battle();
private:
    int m_MarioWinChance;
    Mario m_Mario;
};

#endif