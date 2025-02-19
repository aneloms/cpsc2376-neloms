#include <iostream>
#include "game.hpp"

int main() {
    char board[6][7];
    bool gameOver = false;
    char currentPlayer = 'X';

    printRules();

    makeBoard(board);

    while (!gameOver) {
        displayBoard(board);

        bool validMove = false;
        while (!validMove) {
            int column = getPlayerMove();
            validMove = play(board, column, currentPlayer);

            if (!validMove) {
                std::cout << "Invalid move. Try again.\n";
            }
        }

        GameState status = gameStatus(board);

        if (status == PLAYER_1_WINS) {
            std::cout << "Player 1 (X) wins!\n";
            gameOver = true;
        } else if (status == PLAYER_2_WINS) {
            std::cout << "Player 2 (O) wins!\n";
            gameOver = true;
        } else if (status == DRAW) {
            std::cout << "It's a draw!\n";
            gameOver = true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        if (gameOver && askPlayAgain()) {
            gameOver = false;
            makeBoard(board);
        }
    }

    return 0;
}
