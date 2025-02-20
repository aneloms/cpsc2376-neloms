#include "game.hpp"
#include <iostream>

void makeBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            board[i][j] = '.';
}

void displayBoard(const char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "---------------\n0 1 2 3 4 5 6\n";
}

bool play(char board[6][7], int column, char token) {
    if (column < 0 || column >= 7) return false; 

    for (int i = 5; i >= 0; i--) {
        if (board[i][column] == '.') {
            board[i][column] = token;
            return true;
        }
    }
    return false; 
}

GameState gameStatus(const char board[6][7]) {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            char token = board[i][j];
            if (token == '.') continue;

            if (j + 3 < 7 && token == board[i][j+1] && token == board[i][j+2] && token == board[i][j+3])
                return (token == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;

            if (i + 3 < 6 && token == board[i+1][j] && token == board[i+2][j] && token == board[i+3][j])
                return (token == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;

            if (i + 3 < 6 && j + 3 < 7 && token == board[i+1][j+1] && token == board[i+2][j+2] && token == board[i+3][j+3])
                return (token == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;

            if (i + 3 < 6 && j - 3 >= 0 && token == board[i+1][j-1] && token == board[i+2][j-2] && token == board[i+3][j-3])
                return (token == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }

    for (int j = 0; j < 7; j++) {
        if (board[0][j] == '.')
            return ONGOING; 
    }
    return DRAW;
}

void printRules() {
    std::cout << "Welcome to Connect Four!\n"
              << "Players take turns dropping pieces into columns (0-6).\n"
              << "First to connect four in a row wins!\n";
}

int getPlayerMove() {
    int column;
    while (true) {
        std::cout << "Enter a column (0-6): ";
        std::cin >> column;

        if (std::cin.fail() || column < 0 || column > 6) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Try again.\n";
        } else {
            return column;
        }
    }
}

bool askPlayAgain() {
    char choice;
    std::cout << "Play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
