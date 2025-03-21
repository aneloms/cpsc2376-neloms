#include "game.h"

Game::Game() : currentPlayer(PLAYER_1), board(ROWS, std::vector<Cell>(COLS, EMPTY)) {

}

bool Game::play(int column) {
    if (column < 0 || column >= COLS) return false;
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][column] == EMPTY) {
            board[row][column] = (currentPlayer == PLAYER_1) ? PLAYER_1 : PLAYER_2;
            currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            return true;
        }
    }
    return false;
}

Status Game::status() const {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] != EMPTY && checkWin(row, col, board[row][col])) {
                return (board[row][col] == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }
    return isBoardFull() ? DRAW : ONGOING;
}

bool Game::checkWin(int row, int col, Cell player) const {

    const int directions[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};
    for (const auto& dir : directions) {
        int count = 1;
        for (int step = 1; step < 4; step++) {
            int r = row + step * dir[0], c = col + step * dir[1];
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != player) break;
            count++;
        }
        for (int step = 1; step < 4; step++) {
            int r = row - step * dir[0], c = col - step * dir[1];
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != player) break;
            count++;
        }
        if (count >= 4) return true;
    }
    return false;
}

bool Game::isBoardFull() const {

    for (int col = 0; col < COLS; col++)
        if (board[0][col] == EMPTY) return false;
    return true;
}

void Game::display() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {

    for (int row = 0; row < Game::ROWS; row++) {
        for (int col = 0; col < Game::COLS; col++) {
            char symbol = (game.board[row][col] == PLAYER_1) ? 'X' : (game.board[row][col] == PLAYER_2) ? 'O' : '.';
            os << symbol << " ";
        }
        os << "\n";
    }
    return os;
}