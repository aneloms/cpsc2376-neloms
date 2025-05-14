#include "game.hpp"

Game::Game() : currentPlayer(Player::PLAYER_X), gameState(GameState::IN_PROGRESS) {
    board = std::vector<std::vector<Player>>(6, std::vector<Player>(7, Player::NONE));
}

void Game::play() {
    while (gameState == GameState::IN_PROGRESS) {
        draw();
        handleInput();
        if (checkWin()) {
            gameState = (currentPlayer == Player::PLAYER_X) ? GameState::PLAYER_X_WINS : GameState::PLAYER_O_WINS;
            break;
        }
        if (checkDraw()) {
            gameState = GameState::DRAW;
            break;
        }
        currentPlayer = (currentPlayer == Player::PLAYER_X) ? Player::PLAYER_O : Player::PLAYER_X;
    }

    draw();
    std::cout << (gameState == GameState::DRAW ? "It's a draw!" : (currentPlayer == Player::PLAYER_X ? "Player O wins!" : "Player X wins!")) << std::endl;
}

void Game::draw() {
    std::cout << "\nCurrent Board:\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == Player::NONE)
                std::cout << ".";
            else if (board[i][j] == Player::PLAYER_X)
                std::cout << "X";
            else
                std::cout << "O";
            if (j < 6) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 5) std::cout << "-----------------------------\n";
    }
}

void Game::handleInput() {
    int col;
    std::cout << "Player " << (currentPlayer == Player::PLAYER_X ? "X" : "O") << ", enter column (1-7): ";
    std::cin >> col;
    col--; 

    if (col < 0 || col >= 7 || !isValidMove(col)) {
        std::cout << "Invalid move. Try again.\n";
        handleInput();
    } else {
        int row = getRowForColumn(col);
        board[row][col] = currentPlayer;
    }
}

bool Game::isValidMove(int col) {
    return board[0][col] == Player::NONE;
}

int Game::getRowForColumn(int col) {
    for (int i = 5; i >= 0; --i) {
        if (board[i][col] == Player::NONE) {
            return i;
        }
    }
    return -1;
}

bool Game::checkWin() {

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (board[row][col] != Player::NONE &&
                board[row][col] == board[row][col + 1] &&
                board[row][col] == board[row][col + 2] &&
                board[row][col] == board[row][col + 3]) {
                return true;
            }
        }
    }

    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            if (board[row][col] != Player::NONE &&
                board[row][col] == board[row + 1][col] &&
                board[row][col] == board[row + 2][col] &&
                board[row][col] == board[row + 3][col]) {
                return true;
            }
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (board[row][col] != Player::NONE &&
                board[row][col] == board[row + 1][col + 1] &&
                board[row][col] == board[row + 2][col + 2] &&
                board[row][col] == board[row + 3][col + 3]) {
                return true;
            }
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 3; col < 7; ++col) {
            if (board[row][col] != Player::NONE &&
                board[row][col] == board[row + 1][col - 1] &&
                board[row][col] == board[row + 2][col - 2] &&
                board[row][col] == board[row + 3][col - 3]) {
                return true;
            }
        }
    }

    return false;
}

bool Game::checkDraw() {

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (board[row][col] == Player::NONE) {
                return false;
            }
        }
    }
    return true;
}

void Game::restart() {
    gameState = GameState::IN_PROGRESS;
    currentPlayer = Player::PLAYER_X;
    board = std::vector<std::vector<Player>>(6, std::vector<Player>(7, Player::NONE));
}
