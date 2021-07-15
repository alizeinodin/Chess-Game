#include "chessBoard.h"
using namespace std;

ChessBoard &ChessBoard::getInstance()
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
    /*
    for (auto &i : Board[1])
    {
        ChessMan *solider = new pawn("#ffffff");
        i.setPiece(solider);
    }

    for (auto &i : Board[6])
    {
        ChessMan *solider = new pawn("#000000");
        i.setPiece(solider);
    }

    for (auto &i : Board[0])
    {
        if (i.getId().find("A") || i.getId().find("H"))
        {
            ChessMan *piece = new rook("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("B") || i.getId().find("G"))
        {
            ChessMan *piece = new knight("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("C") || i.getId().find("F"))
        {
            ChessMan *piece = new bishop("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("D"))
        {
            ChessMan *piece = new queen("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("E"))
        {
            ChessMan *piece = new king("#ffffff");
            i.setPiece(piece);
        }
    }

    for (auto &i : Board[6])
    {
        if (i.getId().find("A") || i.getId().find("H"))
        {
            ChessMan *piece = new rook("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("B") || i.getId().find("G"))
        {
            ChessMan *piece = new knight("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("C") || i.getId().find("F"))
        {
            ChessMan *piece = new bishop("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("D"))
        {
            ChessMan *piece = new queen("#ffffff");
            i.setPiece(piece);
        }
        if (i.getId().find("E"))
        {
            ChessMan *piece = new king("#ffffff");
            i.setPiece(piece);
        }
    }
    */

    return Board;
}

array<array<string, 8>, 8> ChessBoard::remmeber(string fileName)
{
    map ChessMap <stirng, ChessBoard *>;
    FileConnect File(fileName);
    while (1)
    {
        if(File.eof())
        {
            break;
        }
        string chessMove = File.ReadToFile();
        
    }
    
}