#ifndef MOVE_H
#define MOVE_H

struct Move {
    int startRow, startCol;
    int endRow, endCol; 
    Move(int sRow, int sCol, int eRow, int eCol) 
        : startRow(sRow), startCol(sCol), endRow(eRow), endCol(eCol) {}
};

#endif
