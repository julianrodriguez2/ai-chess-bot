#include "Game.h"
#include <iostream>

Game::Game() {
    initializeGame();
}

void Game::initializeGame() {
    board.setupBoard();
    isWhiteTurn = true;
    gameOver = false;
    moveHistory.clear();
}

void Game::printBoard() const {
    board.printBoard();
}

bool Game::makeMove(int startRow, int startCol, int endRow, int endCol) {
    if (gameOver) {
        std::cout << "Game is over. No more moves can be made.\n";
        return false;
    }

    auto moves = MoveGen::generateAllMoves(board, isWhiteTurn);

    Move move(startRow, startCol, endRow, endCol);
    for (const auto& possibleMove : moves) {
        if (move == possibleMove) { 
            if (board.makeMove(move)) {
                moveHistory.push_back(move);
                isWhiteTurn = !isWhiteTurn;
                return true;
            } else {
                std::cout << "Move is illegal.\n";
                return false;
            }
        }
    }

    std::cout << "Move is not possible.\n";
    return false;
}

void Game::undoMove() {
    if (!moveHistory.empty()) {
        Move lastMove = moveHistory.back();
        board.undoMove(lastMove); 
        moveHistory.pop_back();
        isWhiteTurn = !isWhiteTurn;
    } else {
        std::cout << "No moves to undo.\n";
    }
}

bool Game::checkGameOver() {

    return gameOver;
}
