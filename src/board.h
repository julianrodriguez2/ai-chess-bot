#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"

class Board {
public:
    Piece squares[8][8];

    Board();
    void setupBoard();
    void printBoard();

    bool isValidPosition(int row, int col) const;
    bool isEmpty(int row, int col) const;
    bool isOpponentPiece(int row, int col, bool isWhite) const;
    Piece getPieceAt(int row, int col) const;
    void setPieceAt(int row, int col, const Piece& piece);
    void makeMove(const Move& move);
    void undoMove(const Move& move);

#endif // BOARD_H