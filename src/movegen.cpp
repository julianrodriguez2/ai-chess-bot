#include "MoveGen.h"

bool MoveGen::isSquareUnderAttack(int row, int col, bool byWhite, const Board& board) {
    auto opponentMoves = generateAllMoves(board, byWhite);
    for (const auto& move : opponentMoves) {
        if (move.endRow == row && move.endCol == col) {
            return true;
        }
    }
    return false;
}

bool MoveGen::isSquareUnderAttack(const Board& board, int row, int col, bool byWhite) {
    auto moves = generateAllMoves(board, !byWhite);
    for (const auto& move : moves) {
        if (move.endRow == row && move.endCol == col) {
            return true;
        }
    }
    return false;
}

std::vector<Move> MoveGen::generatePawnMoves(const Board& board, int row, int col, bool isWhite) {
    std::vector<Move> moves;
    int direction = isWhite ? -1 : 1;
    int nextRow = row + direction;

    // Single step forward
    if (board.isValidPosition(row + direction, col) && board.isEmpty(row + direction, col)) {
        moves.emplace_back(row, col, row + direction, col);
        if ((isWhite && row == 6) || (!isWhite && row == 1) && board.isEmpty(row + 2 * direction, col)) {
            moves.emplace_back(row, col, row + 2 * direction, col);
        }
    }

    // Captures
    for (int newCol : {col - 1, col + 1}) {
        if (board.isValidPosition(row + direction, newCol) && board.isOpponentPiece(row + direction, newCol, isWhite)) {
            moves.emplace_back(row, col, row + direction, newCol);
        }
    }

    if ((isWhite && nextRow == 0) || (!isWhite && nextRow == 7)) {
    moves.emplace_back(row, col, nextRow, col);
    }
    return moves;
}

std::vector<Move> MoveGen::generateKnightMoves(const Board& board, int row, int col) {
    std::vector<Move> moves;
    int rowOffsets[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int colOffsets[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];
        if (board.isValidPosition(newRow, newCol) && (board.isEmpty(newRow, newCol) || board.isOpponentPiece(newRow, newCol, board.squares[row][col].getIsWhite()))) {
            moves.emplace_back(row, col, newRow, newCol);
        }
    }
    return moves;
}

std::vector<Move> MoveGen::generateBishopMoves(const Board& board, int row, int col) {
    std::vector<Move> moves;
    int directions[][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (auto& dir : directions) {
        int currentRow = row + dir[0], currentCol = col + dir[1];
        while (board.isValidPosition(currentRow, currentCol)) {
            if (board.isEmpty(currentRow, currentCol)) {
                moves.emplace_back(row, col, currentRow, currentCol);
            } else {
                if (board.isOpponentPiece(currentRow, currentCol, board.squares[row][col].getIsWhite())) {
                    moves.emplace_back(row, col, currentRow, currentCol);
                }
                break;
            }
            currentRow += dir[0];
            currentCol += dir[1];
        }
    }
    return moves;
}

std::vector<Move> MoveGen::generateRookMoves(const Board& board, int row, int col) {
    std::vector<Move> moves;
    int directions[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto& dir : directions) {
        int currentRow = row, currentCol = col;
        while (true) {
            currentRow += dir[0];
            currentCol += dir[1];
            if (!board.isValidPosition(currentRow, currentCol)) break;

            if (board.isEmpty(currentRow, currentCol)) {
                moves.emplace_back(row, col, currentRow, currentCol);
            } else {
                if (board.isOpponentPiece(currentRow, currentCol, board.getPieceAt(row, col).getIsWhite())) {
                    moves.emplace_back(row, col, currentRow, currentCol);
                }
                break;
            }
        }
    }

    return moves;
}

std::vector<Move> MoveGen::generateQueenMoves(const Board& board, int row, int col) {
    std::vector<Move> moves;
    auto rookMoves = generateRookMoves(board, row, col);
    auto bishopMoves = generateBishopMoves(board, row, col);
    moves.insert(moves.end(), rookMoves.begin(), rookMoves.end());
    moves.insert(moves.end(), bishopMoves.begin(), bishopMoves.end());

    return moves;
}

std::vector<Move> MoveGen::generateKingMoves(const Board& board, int row, int col, bool isWhite) {
    std::vector<Move> moves;
    int directions[][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    for (auto& dir : directions) {
        int newRow = row + dir[0], newCol = col + dir[1];
        if (board.isValidPosition(newRow, newCol) && 
            (board.isEmpty(newRow, newCol) || board.isOpponentPiece(newRow, newCol, isWhite))) {
            moves.emplace_back(row, col, newRow, newCol);
        }
    }

    if (!board.getPieceAt(row, col).getHasMoved()) { 
    // Kingside castling
    if (!board.getPieceAt(row, 7).getHasMoved() && 
        board.isEmpty(row, 5) && board.isEmpty(row, 6) &&
        !isSquareUnderAttack(board, row, 4, !isWhite) &&
        !isSquareUnderAttack(board, row, 5, !isWhite)) {
        moves.emplace_back(row, col, row, 6); 
    }
    // Queenside castling
    if (!board.getPieceAt(row, 0).getHasMoved() &&
        board.isEmpty(row, 1) && board.isEmpty(row, 2) && board.isEmpty(row, 3) &&
        !isSquareUnderAttack(board, row, 4, !isWhite) &&
        !isSquareUnderAttack(board, row, 3, !isWhite)) {
        moves.emplace_back(row, col, row, 2); 
    }
}
    return moves;
}

std::vector<Move> MoveGen::generateAllMoves(const Board& board, bool isWhiteTurn) {
    std::vector<Move> allMoves;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board.squares[row][col].getIsWhite() == isWhiteTurn) { 
                switch (board.squares[row][col].getType()) {
                    case 'P': // Pawn
                        {
                            auto moves = generatePawnMoves(board, row, col, isWhiteTurn);
                            allMoves.insert(allMoves.end(), moves.begin(), moves.end());
                        }
                        break;
                    case 'N': // Knight
                        {
                            auto moves = generateKnightMoves(board, row, col);
                            allMoves.insert(allMoves.end(), moves.begin(), moves.end());
                        }
                        break;
                    case 'B': // Bishop
                        {
                            auto moves = generateBishopMoves(board, row, col);
                            allMoves.insert(allMoves.end(), moves.begin(), moves.end());
                        }
                        break;
                    case 'R':
                        {
                            auto moves = generateRookMoves(board, row, col);
                            allMoves.insert(allMoves.end(), moves.begin(), moves.end());
                        }
                    case 'Q':
                        {
                            auto moves = generateQueenMoves(board, row, col);
                            allMoves.insert(allMoves.end(), moves.begin(), moves.end());
                        }
                    case 'K':
                        {
                            auto moves = generateKingMoves(board, row, col, isWhiteTurn);
                            allMoves.insert(allMoves.end(), moves.begin(), moves.end());
                        }
                }
            }
        }
    }
    return allMoves;
}