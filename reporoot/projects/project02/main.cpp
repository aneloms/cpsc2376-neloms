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

    Status result = game.status();
    if (result == PLAYER_1_WINS) {
        std::cout << "Player 1 wins!\n";
    } else if (result == PLAYER_2_WINS) {
        std::cout << "Player 2 wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    return 0;
}
