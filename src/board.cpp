#include "Board.h"
#include <iostream>

Board::Board() {
    setupBoard();
}

void Board::setupBoard() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            squares[row][col] = Piece();
        }
    }

    for (int col = 0; col < 8; ++col) {
        squares[1][col] = Piece('P', true);
    }
    squares[0][0] = Piece('R', true); // Rook
    squares[0][1] = Piece('N', true); // Knight
    squares[0][2] = Piece('B', true); // Bishop
    squares[0][3] = Piece('Q', true); // Queen
    squares[0][4] = Piece('K', true); // King
    squares[0][5] = Piece('B', true); // Bishop
    squares[0][6] = Piece('N', true); // Knight
    squares[0][7] = Piece('R', true); // Rook

    for (int col = 0; col < 8; ++col){
        squares[6][col] = Piece('P', false);
    }

    squares[7][0] = Piece('R', false); // Rook
    squares[7][1] = Piece('N', false); // Knight
    squares[7][2] = Piece('B', false); // Bishop
    squares[7][3] = Piece('Q', false); // Queen
    squares[7][4] = Piece('K', false); // King
    squares[7][5] = Piece('B', false); // Bishop
    squares[7][6] = Piece('N', false); // Knight
    squares[7][7] = Piece('R', false); // Rook
}

void Board::printBoard() {
    for (int row = 7; row >= 0; --row) {
        for (int col = 0; col < 8; ++col) {
            char symbol = squares[row][col].getSymbol();
            std::cout << symbol << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::isValidPosition(int row, int col) const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool Board::isEmpty(int row, int col) const {
    return isValidPosition(row, col) && squares[row][col].getType() == ' ';
}

bool Board::isOpponentPiece(int row, int col, bool isWhite) const {
    if (!isValidPosition(row, col) || isEmpty(row, col)) return false;
    return squares[row][col].getIsWhite() != isWhite;
}

Piece Board::getPieceAt(int row, int col) const {
    if (isValidPosition(row, col)) return squares[row][col];
    return Piece();
}

void Board::setPieceAt(int row, int col, const Piece& piece) {
    if (isValidPosition(row, col)) squares[row][col] = piece;
}

