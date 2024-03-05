#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
private:
    char type;
    bool isWhite;
    bool hasMoved;

public:
    Piece();
    Piece(char type, bool isWhite);

    char getType() const;
    bool getIsWhite() const;
    bool getHasMoved() const;

    void setHasMoved(bool moved);

    char getSymbol() const;
};

#endif // PIECE_H
