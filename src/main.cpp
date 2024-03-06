#include "Board.h"
#include <iostream>

int main() {
    Board chessBoard;

    chessBoard.printBoard();

    std::cout << "Making a move...\n";

    chessBoard.makeMove(6, 0, 5, 0);

    chessBoard.printBoard();

    return 0;
}
