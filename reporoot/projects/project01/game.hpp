#ifndef GAME_HPP
#define GAME_HPP

enum GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

void makeBoard(char board[6][7]);  
void displayBoard(char board[6][7]);  
bool play(char board[6][7], int column, char token);  
GameState gameStatus(char board[6][7]);  
void printRules();  
int getPlayerMove();  
bool askPlayAgain();  

#endif
