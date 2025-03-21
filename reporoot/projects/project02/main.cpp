#include "game.hpp"

int main() {
    Game game;
    
    std::cout << "Starting Connect 4!\n";
    std::cout << game;

    int move;
    while (game.status() == ONGOING) {
        std::cout << "Enter column (0-6): ";
        std::cin >> move;
        game.play(move);
        std::cout << game;
    }

    std::cout << "Game Over!\n";
    return 0;
}
