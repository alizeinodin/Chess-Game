#include "util.h"
#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include <iostream>
#include <map>
#include <array>
#include "chessMan.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"
#include "cell.h"
#include "fileConnect.h"
#include "player.h"
// #include "game.h"

class ChessBoard
{
    private:
    ChessBoard(); // singleton pattern
    std::array<std::array<Cell, 8>, 8> Board;
    FileConnect File;


    public:
    static ChessBoard & getInstance(); // sinleton pattern
    void startboard();
    std::array<std::array<Cell, 8>, 8> remmeber(std::string);
    void order(std::string);
    Cell & search(std::string);
    void randommoves(COLOR);
    void movePiece(std::string);
    ChessMan * attack(MOVE);
    int threat(COLOR);
};


#endif /* _CHESSBOARD_H*/
