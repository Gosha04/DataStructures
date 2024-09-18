#include "Game.h"

Game::Game() : m_world(1, 5, 20, 20, 20, 20, 20), m_goomba(), m_mario() {

}

Game::Game(int L, int N, int life, int x, int m, int c, int g, int k) : m_world(L, N, x, m, c, g, k),
m_goomba(80, 1), m_koopa(65, 1), m_bowser(50, 2), m_mario(life) {
    currSpotChar = m_world.getCurrSpotChar(m_world.getM_Hrow(), m_world.getM_Hcolumn()); 
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
            if (enemy.equals(m_bowser)) {
                warp();
            }
        }
}

void Game::warp() {
    currSpotChar = m_world.getCurrSpotChar(m_world.nextLevel()); 
}

void Game::interact() {
    switch (currSpotChar) {
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
            warp();
            break;
        default:
            break;
    }
}

// int main(int argc, char const *argv[])
// {
//     Game game(3, 5, 2);
//     return 0;
// }
