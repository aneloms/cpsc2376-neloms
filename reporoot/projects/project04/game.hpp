#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>

enum class Player { NONE, PLAYER_X, PLAYER_O };
enum class GameState { IN_PROGRESS, PLAYER_X_WINS, PLAYER_O_WINS, DRAW };

class Game {
public:
    Game();
    void play();
    void draw();  
    void handleInput();  
    GameState getGameState() const;  
    void restart(); 

private:
    bool checkWin(); 
    bool checkDraw();  
    bool isValidMove(int col);  
    int getRowForColumn(int col); 

    std::vector<std::vector<Player>> board; 
    Player currentPlayer; 
    GameState gameState; 
};

#endif
