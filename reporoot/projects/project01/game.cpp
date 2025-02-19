#include "game.hpp"
#include <iostream>

void makeBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = '.';
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
    if (column < 0 || column >= 7) {
        return false;
    }

    for (int i = 5; i >= 0; i--) {  
        if (board[i][column] == '.') {  
            board[i][column] = token;
            return true;
        }
    }
    return false;
}

GameState gameStatus(char board[6][7]) {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != '.' && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3]) {
                return (board[i][j] == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 3; i++) {
            if (board[i][j] != '.' && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j]) {
                return (board[i][j] == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != '.' && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3]) {
                return (board[i][j] == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            if (board[i][j] != '.' && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3]) {
                return (board[i][j] == 'X') ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    for (int j = 0; j < 7; j++) {
        if (board[0][j] == '.') {  
            return ONGOING;  
        }
    }

    return DRAW;
}

void printRules() {
    std::cout << "Welcome to Connect Four!\n";
    std::cout << "Players take turns dropping pieces into the columns (0-6).\n";
    std::cout << "The first player to connect four in a row wins!\n";
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
