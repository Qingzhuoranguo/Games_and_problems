#include "../games.h"

Game::Game (): GameStatus(ON) {

}

void Game::Settle () {
    std::cout << "The game cannot settle now\n";
    return;
}