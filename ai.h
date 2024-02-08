#ifndef AI_H
#define AI_H

#include "board.h"

class AI {
public:
    static int minimax(Board &board, int depth, bool isMaximizingPlayer);
    static int evaluateBoard(const Board &board);
    static int bestMove(Board &board, int depth);
};

#endif // AI_H
