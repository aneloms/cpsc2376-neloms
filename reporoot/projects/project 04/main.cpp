#include <iostream>
#include "game.hpp"

int main() {
    Game game;
    int column;

    while (game.status() == GameStatus::Ongoing) {
        game.display();
        std::cout << "Player " << (game.currentPlayer() == Player::Player1 ? "1 (X)" : "2 (O)") 
                  << ", enter a column (0-6): ";
        std::cin >> column;

        if (column < 0 || column >= 7) {
            std::cout << "Invalid column. Please try again." << std::endl;
            continue;
        }

        game.play(column);
    }

    game.display();

    if (game.status() == GameStatus::Player1Wins) {
        std::cout << "Player 1 (X) wins!" << std::endl;
    } else if (game.status() == GameStatus::Player2Wins) {
        std::cout << "Player 2 (O) wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    char restart;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> restart;

    if (restart == 'y' || restart == 'Y') {
        game.reset();
        main();
    }

    return 0;
}
