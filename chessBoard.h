#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include <iostream>
#include <array>

class ChessBoard
{
    private:
    ChessBoard(); // singleton pattern
    std::array<std::array<Check, 8>, 8> Board;

    public:
    static ChessBoard & getInstance(); // sinleton pattern
    std::array<std::array<Check, 8>, 8> start();
    std::array<std::array<Check, 8>, 8> remmeber();
    
};
#endif /* _CHESSBOARD_H*/
