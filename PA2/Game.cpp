#include "Game.h"

Game::Game() : m_world(0, 0), m_goomba(), m_mario() {

}

Game::Game(int L, int N, int life) : m_world(L, N), m_goomba(80, 1), m_koopa(65, 1), m_bowser(50, 2), m_mario(life) {
    currSpot = m_world.nextLevel();
}

Game::~Game() {

}

void Game::battle(Enemy enemy) {
    if (enemy.battleMath() == false) {
        if (m_mario.getPowLevel() == 0) {
            m_mario.resetEnemiesKilled();
            }
        m_mario.decreasePowLevel(m_goomba.getEnemyPowLevel());
        } else {
            m_mario.increaseEnemiesKilled();
        }
}

void Game::interact() {
    switch (currSpot) {
        case 'c':
            m_mario.addCoin();
            break;
        case 'm':
            m_mario.addPow();
            break;
        case 'g':
            battle(m_goomba);
            // Movement
            break;
        case 'k':
            battle(m_koopa);
            // Movement
            break;
        case 'b':
            battle(m_bowser);
            // Warp
            break;
        case 'w':
            
            break;
        default:
            currSpot = 'x';
            break;
    }
}







// char spot;
//     switch (c)
//     {
//     case 'c':
//         spot = c;
//         break;
//     case 'm':
//        spot = c;
//         break;
//     case 'g':
//         spot = c;
//         break;
//     case 'k':
//         spot = c;
//         break;
//     case 'b':
//         spot = c;
//         break;
//     case 'w':
//         spot = c;
//         break;
//     default:
//         spot = 'x';
//         break;
//     }
//     return spot;