#include "include/chessBoard.h"
using namespace std;

ChessBoard &ChessBoard::getInstance()
{
    static ChessBoard board;
    return board;
}

ChessBoard::ChessBoard()
{
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

array<array<Cell, 8>, 8> ChessBoard::remmeber(string fileName)
{
    start();
    FileConnect File;
    File.addFile(fileName);
    while (1)
    {
        if (File.getFile().eof())
        {
            break;
        }
        string chessRemmber = File.ReadFromFile();
        updateBoard(chessRemmber.substr(2, 3), chessRemmber.substr(4, 5));
    }
    return Board;
}

Cell &ChessBoard::search(string ID)
{
    for (auto &i : Board)
    {
        for (auto &j : i)
        {
            if (j.getId() == ID)
            {
                return j;
            }
        }
    }
    return Board[0][0]; // for warning
}

void ChessBoard::updateBoard(string first, string second)
{
    Cell firstCell = search(first);
    Cell secondCell = search(second);

    ChessMan *tempPiece = nullptr;
    tempPiece = firstCell.getPiece();

    firstCell.empty();
    if (secondCell.getPiece() != nullptr)
    {
    }
    secondCell.setPiece(tempPiece);
}

ChessMan *ChessBoard::makePiece(char selectPiece, string color)
{
    ChessMan *piece = nullptr;
    if (selectPiece == 'K')
    {
        // piece = new king(color);
    }
    else if (selectPiece == 'Q')
    {
        // piece = new queen(color);
    }
    else if (selectPiece == 'R')
    {
        // piece = new rook(color);
    }
    else if (selectPiece == 'B')
    {
        // piece = new bishop(color);
    }
    else if (selectPiece == 'H')
    {
        // piece = new knight(color);
    }
    else if (selectPiece == 'P')
    {
        // piece = new pawn(color);
    }
    else
    {
        throw invalid_argument("ERROR: invalid order in make piece");
    }
    return piece;
}

void ChessBoard::order(string order)
{
    Cell cell = search(order.substr(1, 2));
//    cell.getPiece()->movePiece(order.substr(3, 4));
    save(order);
}

void ChessBoard::undo()
{
    string move = File.undo();
    updateBoard(move.substr(3, 4), move.substr(1, 2));
}

void ChessBoard::setFile(string player1, string player2, string gamesName)
{
    string fileName = player1 + player2 + gamesName + string(".acd");
    File.addFile(fileName);
}

void ChessBoard::save(string order)
{
    File.WriteToFile(order);
}
