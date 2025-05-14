#include <iostream>
#include "game.hpp"

int main() {
    Game game;
    game.play();

    char restartChoice;
    std::cout << "Do you want to play again? (Y/N): ";
    std::cin >> restartChoice;

    while (restartChoice == 'Y' || restartChoice == 'y') {
        game.restart();
        game.play();
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> restartChoice;
    }

    return 0;
}
