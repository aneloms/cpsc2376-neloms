#include "game.hpp"
#include <iostream>

Game::Game()
    : m_board(6, std::vector<Player>(7, Player::None)), 
      m_currentPlayer(Player::Player1),              
      m_status(GameStatus::Ongoing)                     
{
}

void Game::play(int column) {
    if (column < 0 || column >= 7 || m_status != GameStatus::Ongoing) {
        return; 
    }


    for (int row = 5; row >= 0; --row) {
        if (m_board[row][column] == Player::None) {
            m_board[row][column] = m_currentPlayer;
            if (checkWin(row, column)) {
                m_status = (m_currentPlayer == Player::Player1) ? GameStatus::Player1Wins : GameStatus::Player2Wins;
            } else {

                m_currentPlayer = (m_currentPlayer == Player::Player1) ? Player::Player2 : Player::Player1;
            }
            return;
        }
    }
}

void Game::reset() {
    m_board = std::vector<std::vector<Player>>(6, std::vector<Player>(7, Player::None));
    m_currentPlayer = Player::Player1;
    m_status = GameStatus::Ongoing;
}

GameStatus Game::status() const {
    return m_status;
}

Player Game::currentPlayer() const {
    return m_currentPlayer;
}

const std::vector<std::vector<Player>>& Game::board() const {
    return m_board;
}

void Game::display() const {
    for (const auto& row : m_board) {
        for (const auto& cell : row) {
            char displayChar = (cell == Player::None) ? '.' : (cell == Player::Player1) ? 'X' : 'O';
            std::cout << displayChar << " ";
        }
        std::cout << std::endl;
    }
}

bool Game::checkWin(int row, int col) {
  
    return checkDirection(row, col, 0, 1) ||
           checkDirection(row, col, 1, 0) ||
           checkDirection(row, col, 1, 1) ||
           checkDirection(row, col, 1, -1);   
}

bool Game::checkDirection(int row, int col, int dRow, int dCol) {
    Player player = m_board[row][col];
    int count = 1;

    for (int i = 1; i < 4; ++i) {
        int r = row + i * dRow;
        int c = col + i * dCol;
        if (r >= 0 && r < 6 && c >= 0 && c < 7 && m_board[r][c] == player) {
            ++count;
        } else {
            break;
        }
    }

    for (int i = 1; i < 4; ++i) {
        int r = row - i * dRow;
        int c = col - i * dCol;
        if (r >= 0 && r < 6 && c >= 0 && c < 7 && m_board[r][c] == player) {
            ++count;
        } else {
            break;
        }
    }

    return count >= 4;
}
