#include <iostream>
#include "games.h"


int main () {
    Connect4 instance;
    Game *ptr = &instance;

    int a = 1, b = 2;
    std::cout << ptr->MakeDecision(&a) << std::endl;
    std::cout << ptr->MakeDecision(&b) << std::endl;
    std::cout << ptr->MakeDecision(&a) << std::endl;
    std::cout << ptr->MakeDecision(&b) << std::endl;
    std::cout << ptr->MakeDecision(&a) << std::endl;
    std::cout << ptr->MakeDecision(&b) << std::endl;
    std::cout << ptr->MakeDecision(&a) << std::endl;
    std::cout << ptr->MakeDecision(&b) << std::endl;

    std::cout << "checkwin " << ptr->getGameStatus() << std::endl;
    ptr->Settle();
    return 0;
}