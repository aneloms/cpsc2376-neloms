#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

// Enum for game status
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

// Enum for board cells
enum Cell { EMPTY, PLAYER_1, PLAYER_2 };

class Game {
private:
    std::vector<std::vector<Cell>> board;
    int currentPlayer;

public:
    Game();  // Constructor

    void play(int column);   // Handles a move
    Status status() const;   // Checks game state
    void display() const;    // Prints board

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif
