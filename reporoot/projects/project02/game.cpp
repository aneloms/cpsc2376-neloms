#include "game.hpp"

Game::Game() : board(6, std::vector<Cell>(7, EMPTY)), currentPlayer(PLAYER_1) {}

void Game::play(int column) {
    if (column < 0 || column >= 7) {
        std::cout << "Invalid move. Choose a column between 0 and 6.\n";
        return;
    }

    for (int row = 5; row >= 0; --row) {
        if (board[row][column] == EMPTY) {
            board[row][column] = static_cast<Cell>(currentPlayer);
            if (checkWin(row, column)) {
                std::cout << "Player " << (currentPlayer == PLAYER_1 ? "1" : "2") << " wins!\n";
            }
            currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            return;
        }
    }

    std::cout << "Column is full. Try a different column.\n";
}

bool Game::checkWin(int row, int col) const {
    Cell player = board[row][col];
    if (player == EMPTY) return false;

    int directions[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};

    for (auto [dx, dy] : directions) {
        int count = 1;
        
        for (int i = 1; i < 4; ++i) {
            int r = row + dx * i, c = col + dy * i;
            if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == player) count++;
            else break;
        }

        for (int i = 1; i < 4; ++i) {
            int r = row - dx * i, c = col - dy * i;
            if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == player) count++;
            else break;
        }

        if (count >= 4) return true;
    }

    return false;
}

bool Game::checkDraw() const {
    for (int col = 0; col < 7; ++col) {
        if (board[0][col] == EMPTY) return false;
    }
    return true;
}

Status Game::status() const {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (board[row][col] != EMPTY && checkWin(row, col)) {
                return (board[row][col] == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    return checkDraw() ? DRAW : ONGOING;
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
