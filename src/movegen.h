#ifndef MOVEGEN_H
#define MOVEGEN_H

#include "board.h"
#include "move.h"

#include <vector>

class MoveGen {
public:
    static std::vector<Move> generateAllMoves(const Board& board, bool isWhiteTurn);
    static bool isSquareUnderAttack(const Board& board, int row, int col, bool byWhite);


private:
    static std::vector<Move> generatePawnMoves(const Board& board, int row, int col, bool isWhite);
    static std::vector<Move> generateKnightMoves(const Board& board, int row, int col);
    static std::vector<Move> generateBishopMoves(const Board& board, int row, int col);
    static std::vector<Move> generateRookMoves(const Board& board, int row, int col);
    static std::vector<Move> generateQueenMoves(const Board& board, int row, int col);
    static std::vector<Move> generateKingMoves(const Board& board, int row, int col, bool isWhite);
    bool MoveGen::isSquareUnderAttack(int row, int col, bool byWhite, const Board& board);

    static void addMoveIfValid(std::vector<Move>& moves, const Board& board, int startRow, int startCol, int endRow, int endCol, bool isWhite);
};

#endif // MOVEGEN_H
