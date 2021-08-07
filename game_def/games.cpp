#include "../games.h"


int Game::GameCount = 0;

Game::Game (): GameStatus(ON) {
    GameCount++;
}

Game::~Game(){
    GameCount --;
}


void Game::Settle () {
    std::cout << "The game cannot settle now\n";
    return;
}
