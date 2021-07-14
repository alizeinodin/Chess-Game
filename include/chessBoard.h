#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include <iostream>
#include <map>
#include <array>
#include "cell.h"

class ChessBoard
{
    private:
    ChessBoard(); // singleton pattern
    std::array<std::array<Cell, 8>, 8> Board;

    public:
    static ChessBoard & getInstance(); // sinleton pattern
    std::array<std::array<Cell, 8>, 8> start();
    std::array<std::array<Cell, 8>, 8> remmeber();
    std::map<std::string, int> threats();
    
    
};
#endif /* _CHESSBOARD_H*/
