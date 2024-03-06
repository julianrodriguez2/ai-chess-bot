#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "MoveGen.h"
#include <vector>

class Game {
private:
    Board board;
    bool isWhiteTurn;
    bool gameOver;
    std::vector<Move> moveHistory;

public:
    Game();

    void initializeGame();

    void printBoard() const;

    bool makeMove(int startRow, int startCol, int endRow, int endCol);

    void undoMove();

    bool checkGameOver();

    // Getters
    bool getIsWhiteTurn() const { return isWhiteTurn; }
    bool getGameOver() const { return gameOver; }

};

#endif // GAME_H
