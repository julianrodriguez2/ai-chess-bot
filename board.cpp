#include "board.h"
#include <iostream>

using namespace std;

Board::Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares[i][j] = ' ';
        }
    }

     // Place pawns
    for (int i = 0; i < 8; i++) {
        squares[1][i] = 'P'; // White pawns
        squares[6][i] = 'p'; // Black pawns
    }

    // Place other pieces
    // White pieces
    squares[0][0] = 'R'; squares[0][7] = 'R';
    squares[0][1] = 'N'; squares[0][6] = 'N';
    squares[0][2] = 'B'; squares[0][5] = 'B';
    squares[0][3] = 'Q'; squares[0][4] = 'K';

    // Black pieces
    squares[7][0] = 'r'; squares[7][7] = 'r';
    squares[7][1] = 'n'; squares[7][6] = 'n';
    squares[7][2] = 'b'; squares[7][5] = 'b';
    squares[7][3] = 'q'; squares[7][4] = 'k';
}


void Board::printBoard() const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << squares[i][j] << " ";
        }
        cout << endl;
    }
}