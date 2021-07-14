#include "chessBoard.h"
using namespace std;

ChessBoard & ChessBoard::getInstance()
{
    static ChessBoard board;
    return board;
}

ChessBoard::ChessBoard()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {

        }
    }
}

void ChessBoard::testColor()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout << Board[i][j].getId() << " : " << Board[i][j].getColor() << "\t";
        }
        cout << endl;
    }
}

array<array<Cell, 8>, 8> ChessBoard::start()
{
    // for(auto & i: Board[1])
    // {
    //     ChessMan * solider = new pawn("#ffffff");
    //     i.setNut(solider);
    // }

    // for(auto & i: Board[6])
    // {
    //     ChessMan * solider = new pawn("#000000");
    //     i.setNut(solider);
    // }

    for(auto & i: Board[0])
    {
        if(i.getId().find("A"))
        {

        }
    }
}