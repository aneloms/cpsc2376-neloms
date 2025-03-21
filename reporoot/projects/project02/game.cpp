#include "game.hpp"

Game::Game() : board(6, std::vector<Cell>(7, EMPTY)), currentPlayer(PLAYER_1) {}

void Game::play(int column) {


    if (column < 0 || column >= 7) {
        std::cout << "Invalid move. Choose a column between 0 and 6.\n";
        return;
    }

    for (int row = 5; row >= 0; --row) {
        if (board[row][column] == EMPTY) {
            board[row][column] = (currentPlayer == PLAYER_1) ? PLAYER_1 : PLAYER_2;
            currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            return;
        }
    }

    std::cout << "Column is full. Try a different column.\n";
}

Status Game::status() const {

    return ONGOING;
}

void Game::display() const {
    for (const auto& row : board) {
        for (Cell cell : row) {
            char symbol = (cell == PLAYER_1) ? 'X' : (cell == PLAYER_2) ? 'O' : '.';
            std::cout << symbol << " ";
        }
        std::cout << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    game.display();
    return os;
}
