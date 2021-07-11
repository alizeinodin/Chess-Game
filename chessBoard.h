#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include <iostream>
#include <array>

class ChessBoard
{
    private:
    ChessBoard(); // singleton pattern
    std::array<std::array<Check, 8>, 8> Board;
    PositiveScore pscore; 
    NegativeScore nscore;


    public:
    static ChessBoard & getInstance(); // sinleton pattern
    std::array<std::array<Check, 8>, 8> start();
    std::array<std::array<Check, 8>, 8> remmeber();
    void addScore(size_t state, int score); // state 1 for psocre, 2 for nscore

    
}

#endif /* _CHESSBOARD_H*/
