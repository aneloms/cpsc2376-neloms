#include <iostream>
#include "game.hpp"

int main() {
    char board[6][7];
    char currentPlayer = 'X';
    bool gameOver = false;

    printRules();

    while (true) {
        makeBoard(board);
        gameOver = false;

        while (!gameOver) {
            displayBoard(board);

            bool validMove = false;
            while (!validMove) {
                int column = getPlayerMove();
                validMove = play(board, column, currentPlayer);
                if (!validMove) std::cout << "Column full or invalid. Try again.\n";
            }

            GameState status = gameStatus(board);

            if (status == PLAYER_1_WINS) {
                displayBoard(board);
                std::cout << "Player 1 (X) wins!\n";
                gameOver = true;
            } else if (status == PLAYER_2_WINS) {
                displayBoard(board);
                std::cout << "Player 2 (O) wins!\n";
                gameOver = true;
            } else if (status == DRAW) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        if (!askPlayAgain()) break;
    }

    return 0;
}
