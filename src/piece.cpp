#include "Piece.h"

Piece::Piece() : type(' '), isWhite(false), hasMoved(false) {}

Piece::Piece(char type, bool isWhite) : type(type), isWhite(isWhite), hasMoved(false) {}

char Piece::getType() const {
    return type;
}

bool Piece::getIsWhite() const {
    return isWhite;
}

bool Piece::getHasMoved() const {
    return hasMoved;
}

void Piece::setHasMoved(bool moved) {
    hasMoved = moved;
}

char Piece::getSymbol() const {
    if (type == ' ') return '.';
    if (isWhite) return type;
    return tolower(type);
}
