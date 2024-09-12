/*
In our simulation, Mario starts with a number of lives, V, which will be provided at runtime.
Mario also has the ability to collect coins. He starts with 0 coins. For every 20 coins collected,
he earns an extra life (and the number of coins resets to 0). At any moment, Mario is in one of 3
power levels, PL0, PL1, and PL2. PL0 is the weakest and PL2 is the strongest. Mario can increase
power levels by coming in contact with a mushroom (a “magic” mushroom), and loses a power level if
hurt by an enemy. More on that later.
*/

#ifndef MARIO_H
#define MARIO_H

class Mario {
public:
    // default constructor
    Mario();
    // overloaded constructor which takes in a parameter for the number of lives
    Mario(int L);
    // virtual destructor
    virtual ~Mario();
    // mutator function for lives
    void SetLives(int L);
    // accessor function for lives
    int GetLives();
    // mutator function for coins
    void SetNumCoins(int coins);
    // accessor function for coins
    int GetNumCoins();
    // mutator function for power level
    void SetPowLevel(int powLevel);
    // accessor function for power level
    int GetPowLevel();
    // resets coins to 0 and adds one life
    void ResetCoins();
    // adds 1 to coins
    void AddCoin();
    // adds 1 pow if you pick up a mushroom
    void AddPow();
    
private:
    int m_lives;
    int m_numCoins;
    int m_powLevel;
};

#endif