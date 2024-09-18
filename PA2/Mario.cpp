#include "Mario.h"

// default mario has 5 lives
Mario::Mario() {
    m_lives = 5;
    m_powLevel = 0;
    m_numCoins = 0;
    m_enemiesKilledOnCurrentLife = 0;
}

// creates a mario with the passed in number of lives
Mario::Mario(int life) {
    m_lives = life;
    m_powLevel = 0;
    m_numCoins = 0;
    m_enemiesKilledOnCurrentLife = 0;
}

Mario::~Mario() {}

// returns marios nnumber of lives
int Mario::getLives() {
    return m_lives;
}

// if mario loses a life he will also reset the counter of the number of enemies he has killed
// also resets mario's power level to 0
void Mario::decreaseLives() {
    m_lives -= 1;
    m_enemiesKilledOnCurrentLife = 0;
    m_powLevel = 0;
}

// returns marios number of coins
int Mario::getNumCoins() {
    return m_numCoins;
}

// allow to set the number of coins
void Mario::setNumCoins(int coins) {
    m_numCoins = coins;
}

// returns marios power level
int Mario::getPowLevel() {
    return m_powLevel;
}

// decreases marios power level by the power level of the enemy
void Mario::decreasePowLevel(int powLevel) {
    // if marios power level is greater or equal to his enemy
    if (m_powLevel >= powLevel) {
        // decrease his power level by the enemys power level
        m_powLevel -= powLevel;
    }
    // if the enemys power level is greater than marios, mario loses a lief
    else {
        decreaseLives();
    }
}

// resets coin count to 0 and adds one life to mario
void Mario::resetCoins() {
    m_numCoins = 0;
    m_lives += 1;
}
// add a coin to marios total when he lands on the spot
void Mario::addCoin() {
    m_numCoins += 1;
}

// if marios power level is less than 2 marios power level increases
void Mario::addPow() {
    if (m_powLevel < 2) {
        m_powLevel++;
    }
}
// changes the number of enemies mario has killed on current life
void Mario::increaseEnemiesKilled() {
    m_enemiesKilledOnCurrentLife += 1;
    // if total number of enemies killed on one life is 7 or more
    // add one life to total lives and reset the counter
    if (m_enemiesKilledOnCurrentLife >= 7) {
        m_lives += 1;
        m_enemiesKilledOnCurrentLife = 0;
    }
}