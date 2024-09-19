/*
Joshua Vaysman || Dylan Barlava
2449656 || 2428584
vaysman@chapman.edu || dbarlava@chapman.edu
CPSC 350-02
PA2
*/

#ifndef MARIO_H
#define MARIO_H

class Mario {
public:
    // default constructor
    Mario();
    // overloaded constructor which takes in a parameter for the number of lives
    Mario(int life);
    // virtual destructor
    virtual ~Mario();
    // mutator function for lives
    void decreaseLives();
    // accessor function for lives
    int getLives();
    // mutator function for coins
    void setNumCoins(int coins);
    // accessor function for coins
    int getNumCoins();
    // mutator function for power level
    void decreasePowLevel(int powLevel);
    // accessor function for power level
    int getPowLevel();
    // resets coins to 0 and adds one life
    void resetCoins();
    // adds a coin to marios total
    void addCoin();
    // adds one pow if you pick up a mushroom
    void addPow();
    // increases number of enemies killed
    void increaseEnemiesKilled();
    // reset enemiesKilled
    void resetEnemiesKilled();
private:
    int m_lives;
    int m_numCoins;
    int m_powLevel;
    int m_enemiesKilledOnCurrentLife;
};

#endif