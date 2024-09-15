#include "Mario.h"

Mario::Mario() {
    m_lives = 5;
    m_powLevel = 0;
    m_numCoins = 0;
    m_enemiesKilledOnCurrentLife = 0;
}

Mario::Mario(int life) {
    m_lives = life;
    m_powLevel = 0;
    m_numCoins = 0;
    m_enemiesKilledOnCurrentLife = 0;
}

Mario::~Mario() {}

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

int Mario::getNumCoins() {
    return m_numCoins;
}

void Mario::setNumCoins(int coins) {
    m_numCoins = coins;
}

int Mario::getPowLevel() {
    return m_powLevel;
}

void Mario::decreasePowLevel(int powLevel) {
    if (m_powLevel >= powLevel) {
        m_powLevel -= powLevel;
    }
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
// increases Marios power level
// If power level is already at 2 it resets it back to 2
void Mario::addPow() {
    m_powLevel += 1;
    if (m_powLevel < 2) {
        m_powLevel = 2;
    }
}
// changes the number of enemies mario has killed on current life
void Mario::increaseEnemiesKilled() {
    m_enemiesKilledOnCurrentLife += 1;
    // if total number of enemies killed on one life is 7 or more
    // add one life to total lives and reset the counter
    if (m_enemiesKilledOnCurrentLife <= 7) {
        m_lives += 1;
        m_enemiesKilledOnCurrentLife = 0;
    }
}