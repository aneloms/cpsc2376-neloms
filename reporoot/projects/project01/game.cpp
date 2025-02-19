#include "game.hpp"
#include <iostream>

void makeBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = '.';  // Empty board cell
        }
    }
}

void displayBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------\n";
    std::cout << "0 1 2 3 4 5 6\n";
}

bool play(char board[6][7], int column, char token) {
    for (int i = 5; i >= 0; i--) {
        if (board[i][column] == '.') {
            board[i][column] = token;
            return true;
        }
    }
    return false;
}

GameState gameStatus(char board[6][7]) {
    std::cout << "Game status check is still incomplete.\n";
    return ONGOING;
}

void printRules() {
    std::cout << "Welcome to Connect Four!\n";
    std::cout << "Players take turns dropping pieces into the columns.\n";
    std::cout << "The first player to connect four in a row wins!\n";
}

int getPlayerMove() {
    int column;
    std::cout << "Enter a column (0-6): ";
    std::cin >> column;
    return column;
}

bool askPlayAgain() {
    char choice;
    std::cout << "Play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
