#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
        char squares[8][8];

        Board();
        void printBoard() const;
};

#endif // BOARD_H