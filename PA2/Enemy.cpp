#include "Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy() {
    m_MarioWinChance = 100;
    Mario mario(3);
    m_Mario = mario;
}

Enemy::Enemy(int marioWinChance, Mario mario) {
    m_MarioWinChance = m_MarioWinChance;
    m_Mario = mario;
}

Enemy::~Enemy() {}

int Enemy::GetMarioWinChance() {
    return m_MarioWinChance;
}

void Enemy::SetMarioWinChance(int chance) {
    m_MarioWinChance = chance;
}

bool Enemy::Battle() {
    int result;
    result = (rand() % 100) + 1;
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