#include "chessBoard.h"
#include "chessMan.h"
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
    FileConnect File(fileName);
    while (1)
    {
        if (File.getFile().eof())
        {
            break;
        }
        string chessRemmber = File.ReadFromFile();
        updateBoard(chessRemmber.substr(2, 3), chessRemmber.substr(4, 5));
    }
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
}

void ChessBoard::updateBoard(string first, string second)
{
    Cell firstCell = search(first);
    Cell secondCell = search(second);

    ChessMan *tempPiece = nullptr;
    tempPiece = firstCell.getPiece();

    firstCell.empty();
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
    cell.getPiece()->movePiece(order.substr(3, 4));
}

void ChessBoard::saveData(string order)
{
}

void ChessBoard::randommoves(COLOR color)
{
    ChessMan *temp;
    vector<int> rndcell;
    string cellid;
    int rand = randomNoGenerator(6);
    switch (rand)
    {
    case QUEEN:
        cellid += 'Q';
        break;
    case KING:
        cellid += 'K';
        break;
    case BISHOP:
        cellid += 'B';
        break;
    case POWN:
        cellid += 'P';
        break;
    case KNIGHT:
        cellid += 'H';
        break;
    case ROOK:
        cellid += 'R';
        break;
    }
    rndcell.push_back(randomNoGenerator(8));
    rndcell.push_back(randomNoGenerator(8));
    string origin;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            temp = Board.at(i).at(j).getPiece();
            if (temp->get_color() == color && temp->get_type() == rand)
            {
                origin = Board.at(i).at(j).getId();
            }
        }
    }
    cellid += origin.substr(0,1);
    cellid += Board.at(rndcell[0]).at(rndcell[1]).getId();
    this->movePiece(cellid);
}

void ChessBoard::movePiece(MOVE move)
{
    ChessMan * attack;
    auto cellsid = cut_str(move);
    Cell cells[2];
    cells[0] = search_cell(cellsid.first, Board);
    cells[1] = search_cell(cellsid.second, Board);
    
    if (!cells[0].getState() && cells[1].getState())
    {
        cells[0].getPiece()->move(move, Board);
        
    }
    else if (!cells[0].getState() && !cells[1].getState())
    {
        attack = cells[0].getPiece()->attack(move, cells[1]);
    }
}