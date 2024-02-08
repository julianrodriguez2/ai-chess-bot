#ifndef MOVEGEN_H
#define MOVEGEN_H

#include "board.h"
#include <vector>

struct Move {
    int startRow, startCol; 
    int endRow, endCol;
    char promotedTo;        // For pawn promotion
    // Additional fields can be added as needed, such as captured piece, en passant, castling, etc.

    // Default constructor
    Move(int sRow, int sCol, int eRow, int eCol, char promo = ' ') :
        startRow(sRow), startCol(sCol), endRow(eRow), endCol(eCol), promotedTo(promo) {}
};

// Function to generate all legal moves for the current board state
std::vector<Move> generateMoves(const Board& board, bool isWhite);

// Individual piece move generation functions
void generatePawnMoves(std::vector<Move>& moves, const Board& board, int row, int col, bool isWhite);
void generateKnightMoves(std::vector<Move>& moves, const Board& board, int row, int col, bool isWhite);
void generateBishopMoves(std::vector<Move>& moves, const Board& board, int row, int col, bool isWhite);
void generateRookMoves(std::vector<Move>& moves, const Board& board, int row, int col, bool isWhite);
void generateQueenMoves(std::vector<Move>& moves, const Board& board, int row, int col, bool isWhite);
void generateKingMoves(std::vector<Move>& moves, const Board& board, int row, int col, bool isWhite);

#endif // MOVEGEN_H
