#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

enum Cell { EMPTY, PLAYER_1, PLAYER_2 };

class Game {
private:
    std::vector<std::vector<Cell>> board;
    int currentPlayer;

    bool checkWin(int row, int col) const; 
    bool checkDraw() const; 

public:
    Game(); 

    void play(int column);   
    Status status() const;   
    void display() const;    

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif
