#include "Enemy.h"
#include <random>
#include <iostream>

// default constructor that makes it imposible for mario to lose
Enemy::Enemy() {
    m_MarioWinChance = 100;
    m_EnemyPowLevel = 1;
    std::srand(time(NULL));
}

// creates an enemy with marios win chance and the power level of the enemy
Enemy::Enemy(int marioWinChance, int enemyPowLevel) {
    m_MarioWinChance = marioWinChance;
    m_EnemyPowLevel = enemyPowLevel;
    std::srand(time(NULL));
}

Enemy::~Enemy() {}

// returns marios win chance
int Enemy::getMarioWinChance() {
    return m_MarioWinChance;
}

// allows to change marios win percentage
void Enemy::setMarioWinChance(int chance) {
    m_MarioWinChance = chance;
}

// sets the enemies power level
void Enemy::setEnemyPowLevel(int powLevel) {
    m_EnemyPowLevel = powLevel;
}

// returns the enemies power level
int Enemy::getEnemyPowLevel() {
    return m_EnemyPowLevel;
}

// returns true if mario won and false if he lost
bool Enemy::battleMath() {
    // generates a random number 1-100
    int result = (rand() % 100) + 1;
    std::cout << "Win chance: " << m_MarioWinChance << std::endl;
    std::cout << "Random number: " << result << std::endl;
    // if the number is less than marios win chance mario wins the battle
    if (result <= m_MarioWinChance) {
        std::cout << "Mario wins the battle" << std::endl;
        return true;
    }
    // if the number is greater than marios win chance mario looses
    else {
        std::cout << "Mario lost" << std::endl;
        return false;
    }
}

// checks to see if two enemies are the sames
bool Enemy::equals(const Enemy& enemy) {
    return (m_MarioWinChance == enemy.m_MarioWinChance) &&
           (m_EnemyPowLevel == enemy.m_EnemyPowLevel);
}

// int main () {
//     Mario mario(5);
//     Enemy koopa(55 ,1);
//     koopa.battleMath();  
// }