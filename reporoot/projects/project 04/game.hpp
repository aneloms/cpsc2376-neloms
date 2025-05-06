#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

enum class Player { None, Player1, Player2 };

enum class GameStatus { Ongoing, Player1Wins, Player2Wins, Draw };

class Game {
public:

    Game();

    void play(int column);

    void reset();

    GameStatus status() const;

    Player currentPlayer() const;

    const std::vector<std::vector<Player>>& board() const;

    void display() const;

private:

    std::vector<std::vector<Player>> m_board;

    Player m_currentPlayer;

    GameStatus m_status;

    bool checkWin(int row, int col);

    bool checkDirection(int row, int col, int dRow, int dCol);
};

#endif 
