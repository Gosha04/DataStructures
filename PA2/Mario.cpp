#include "Mario.h"

Mario::Mario() {
    m_lives = 3;
    m_powLevel = 0;
    m_numCoins = 0;
}

Mario::Mario(int L) {
    m_lives = L;
    m_powLevel = 0;
    m_numCoins = 0;
}

Mario::~Mario() {}

int Mario::GetLives() {
    return m_lives;
}

void Mario::SetLives(int L) {
    m_lives = L;
}

int Mario::GetNumCoins() {
    return m_numCoins;
}

void Mario::SetNumCoins(int coins) {
    m_numCoins = coins;
}

int Mario::GetPowLevel() {
    return m_powLevel;
}

void Mario::SetPowLevel(int powLevel) {
    m_powLevel = powLevel;
}

// resets coin count to 0 and adds one life to mario
void Mario::ResetCoins() {
    m_numCoins = 0;
    m_lives += 1;
}