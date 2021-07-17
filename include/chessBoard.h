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

class ChessBoard
{
    private:
    ChessBoard(); // singleton pattern
    std::array<std::array<Cell, 8>, 8> Board;

    public:
    static ChessBoard & getInstance(); // sinleton pattern
    std::array<std::array<Cell, 8>, 8> start();
    std::array<std::array<Cell, 8>, 8> remmeber(std::string);
    std::map<std::string, int> threats();
    void updateBoard(std::string, std::string);
    Cell & search(std::string);
    ChessMan * makePiece(char, std::string);
    
};
#endif /* _CHESSBOARD_H*/
