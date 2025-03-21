#include "game.h"

int main() {
    Game game;
    int column;
    
    while (game.status() == ONGOING) {
        std::cout << game;
        std::cout << "Enter a column (0-6): ";
        std::cin >> column;
        
        if (!game.play(column)) {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }
    }

    std::cout << game;
    Status result = game.status();
    if (result == PLAYER_1_WINS)
        std::cout << "Player 1 (X) wins!\n";
    else if (result == PLAYER_2_WINS)
        std::cout << "Player 2 (O) wins!\n";
    else
        std::cout << "It's a draw!\n";

    return 0;
}
