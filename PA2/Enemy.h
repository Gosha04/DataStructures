/*
Joshua Vaysman || Dylan Barlava
2449656 || 2428584
vaysman@chapman.edu || dbarlava@chapman.edu
CPSC 350-02
PA2
*/

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    // default constructor
    Enemy();
    // allow user to pass in marios win chance
    Enemy(int marioWinChance, int enemyPowLevel);
    // virtual destructor
    virtual ~Enemy();
    // get marios win chance
    int getMarioWinChance();
    // set the chance that mario wins battle agains the enemy
    void setMarioWinChance(int chance);
    // sets the enemys power level
    void setEnemyPowLevel(int powLevel);
    // returns the enemys power level
    int getEnemyPowLevel();
    // return true if mario wins
    bool battleMath();
    // check if two enemies are equal
    bool equals(const Enemy& enemy);
    
private:
    int m_MarioWinChance;
    int m_EnemyPowLevel;
};

#endif