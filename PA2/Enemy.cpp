#include "Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy() {
    m_MarioWinChance = 100;
    m_enemyPowLevel = 1;
}

Enemy::Enemy(int marioWinChance) {
    m_MarioWinChance = marioWinChance;
    std::srand(time(NULL));
}

Enemy::~Enemy() {}

int Enemy::getMarioWinChance() {
    return m_MarioWinChance;
}

void Enemy::setMarioWinChance(int chance) {
    m_MarioWinChance = chance;
}

bool Enemy::battle() {
    int result = (rand() % 100) + 1;
    std::cout << "Win chance: " << m_MarioWinChance << std::endl;
    std::cout << "Random number: " << result << std::endl;
    if (result <= m_MarioWinChance) {
        std::cout << "Mario wins the battle" << std::endl;
        return true;
    }
    else {
        std::cout << "Mario lost" << std::endl;
        return false;
    }
}

int main () {
    Mario mario(5);
    Enemy koopa(55);
    koopa.battle();  
}