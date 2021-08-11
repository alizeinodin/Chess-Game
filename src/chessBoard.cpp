#include "../include/chessBoard.h"
#include "../include/chessMan.h"
//#include "../include/matexcept.h"
#include <algorithm>
using namespace std;

ChessBoard &ChessBoard::getInstance()
{
    static ChessBoard board;
    return board;
}

ChessBoard::ChessBoard()
{
}

void ChessBoard::startboard()
{

    for (auto &i : Board[1])
    {
        ChessMan *solider = new pawn("White");
        i.setPiece(solider);
    }

    for (auto &i : Board[6])
    {
        ChessMan *solider = new pawn("Black");
        i.setPiece(solider);
    }
    for (auto &i : Board[0])
    {
        if (i.getId().at(0) == 'A' || i.getId().at(0) == 'H')
        {
            ChessMan *piece = new rook("White");
            i.setPiece(piece);
        }
        if (i.getId().at(0) == 'B' || i.getId().at(0) == 'G')
        {
            ChessMan *piece = new knight("White");
            i.setPiece(piece);
        }
        if (i.getId().at(0) == 'C' || i.getId().at(0) == 'F')
        {
            ChessMan *piece = new bishop("White");
            i.setPiece(piece);
        }
        if (i.getId().at(0) == 'D')
        {
            ChessMan *piece = new queen("White");
            i.setPiece(piece);
        }
        if (i.getId().at(0) == 'E')
        {
            ChessMan *piece = new king("White");
            i.setPiece(piece);
        }
    }

    for (auto &i : Board[7])
    {
        if (i.getId().at(0) == 'A' || i.getId().at(0) == 'H')
        {
            ChessMan *piece = new rook("Black");
            i.setPiece(piece);
        }
        else if (i.getId().at(0) == 'B' || i.getId().at(0) == 'G')
        {
            ChessMan *piece = new knight("Black");
            i.setPiece(piece);
        }
        else if (i.getId().at(0) == 'C' || i.getId().at(0) == 'F')
        {
            ChessMan *piece = new bishop("Black");
            i.setPiece(piece);
        }
        else if (i.getId().at(0) == 'D')
        {
            ChessMan *piece = new queen("Black");
            i.setPiece(piece);
        }
        else if (i.getId().at(0) == 'E')
        {
            ChessMan *piece = new king("Black");
            i.setPiece(piece);
        }
    }
}

Cell &ChessBoard::search(std::string str)
{
    char character[] = "a";
    get_char(str, character);
    string temp = "ABCDEFGH";
    int y = temp.find(character);
    int x = get_num(str) - 1;
    if (Board.at(x).at(y).getId() == str)
    {
        return Board.at(x).at(y);
    }

    throw out_of_range("cell not exist");
}

MOVE ChessBoard::randommoves(COLOR color)
{
    cout << "\ncolor: " << color << endl;
    ChessMan *temp;
    string cellid;
    vector<ID> man;
    string origin;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (!Board.at(i).at(j).getState())
            {
                if (Board.at(i).at(j).getPiece()->get_color() == color)
                {
                    man.push_back(Board.at(i).at(j).getId());
                }
            }
        }
    }
    string tempman = man.at(randomNoGenerator(man.size() - 1));
    temp = search_cell(tempman, Board)->getPiece();
    switch (temp->get_type())
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
    case PAWN:
        cellid += 'P';
        break;
    case KNIGHT:
        cellid += 'H';
        break;
    case ROOK:
        cellid += 'R';
        break;
    }
    cellid += tempman;
    cellid += temp->get_random(tempman);
    cout << cellid << endl;
    return cellid;
}

void ChessBoard::movePiece(MOVE move)
{
    auto cellsid = cut_str(move);
    Cell *cells;
    cells = search_cell(cellsid.first, Board);
    //cout << cells.getId();
    if (!cells->getState())
    {
        cells->getPiece()->move(move, Board);
        return;
    }
    throw invalid_argument("cell is empty");
}

ChessMan *ChessBoard::attack(MOVE move)
{
    ChessMan *temp;
    auto cellsid = cut_str(move);
    Cell *cells[2];
    cells[0] = search_cell(cellsid.first, Board);
    cells[1] = search_cell(cellsid.second, Board);
    temp = cells[0]->getPiece();
    temp->access(cells[0]->getId(), Board);
    if (!cells[0]->getState() && !cells[1]->getState())
    {
        return temp->attack(move, cells);
    }
    throw invalid_argument("can not attack");
}

int ChessBoard::threat(COLOR color)
{
    std::map<std::string, int> temp;
    auto it = temp.begin();
    int score = 0;
    //cout << "len:  " << Board.size() << endl;
    for (auto &i : Board)
    {
        //cout << "len 2:  " << i.size() << endl;
        for (auto &j : i)
        {
            if (j.getPiece() != nullptr)
            {
                //cout << j.getPiece()->get_type() << "\t";
                //cout << j.getPiece()->get_type() << "\t" << j.getPiece()->get_color() << endl;
                if (j.getPiece()->get_color() == color)
                {
                    //cerr << "id: " << j.getId() << endl;
                    temp = j.getPiece()->threat(j.getId(), Board);
                    it = temp.begin();
                    for (size_t i = 0; i < temp.size(); i++)
                    {
                        score += it->second;
                        it++;
                    }
                }
            }
        }
    }
    return score;
}

void ChessBoard::undo(MOVE move, ChessMan *attackp)
{
    auto cellsid = cut_str(move);
    Cell *cells[2];
    Cell *temp;
    cells[0] = search_cell(cellsid.second, Board);
    cells[1] = search_cell(cellsid.first, Board);
    if (cellsid.second == "C1" || cellsid.second == "G1" || cellsid.second == "C8" || cellsid.second == "G8")
    {
        king *k;
        if (cells[0]->getPiece()->get_type() == KING)
        {
            k = dynamic_cast<king *>(cells[0]->getPiece());
            if (k->iscastling)
            {
                if (k->get_color() == "White")
                {
                    cells[1] = search_cell("F1", Board);
                    if (!cells[1]->getState())
                    {
                        if (cells[1]->getPiece()->get_type() == ROOK)
                        {
                            temp = search_cell("H1", Board);
                            temp->setPiece(cells[1]->getPiece());
                            cells[1]->empty();
                        }
                    }
                    cells[1] = search_cell("D1", Board);
                    if (!cells[1]->getState())
                    {
                        if (cells[1]->getPiece()->get_type() == ROOK)
                        {
                            temp = search_cell("A1", Board);
                            temp->setPiece(cells[1]->getPiece());
                            cells[1]->empty();
                        }
                    }
                }
                else
                {
                    cells[1] = search_cell("F8", Board);
                    if (!cells[1]->getState())
                    {
                        if (cells[1]->getPiece()->get_type() == ROOK)
                        {
                            temp = search_cell("H8", Board);
                            temp->setPiece(cells[1]->getPiece());
                            cells[1]->empty();
                        }
                    }
                    cells[1] = search_cell("D8", Board);
                    if (!cells[1]->getState())
                    {
                        if (cells[1]->getPiece()->get_type() == ROOK)
                        {
                            temp = search_cell("A8", Board);
                            temp->setPiece(cells[1]->getPiece());
                            cells[1]->empty();
                        }
                    }
                }
            }
        }
        cells[0] = search_cell(cellsid.second, Board);
        cells[1] = search_cell(cellsid.first, Board);
    }
    if (cells[0]->getPiece()->get_type() == PAWN)
    {
        pawn *p = dynamic_cast<pawn *>(cells[0]->getPiece());
        if (!p->enpassantundo.empty())
        {
            cellsid = cut_str(p->enpassantundo);
            if (cellsid.second == cells[0]->getId())
            {
                cells[1]->setPiece(cells[0]->getPiece());
                cells[0]->empty();
                cells[0] = search_cell(cellsid.first, Board);
                if (move.at(5) == '1')
                {
                    cells[0]->setPiece(attackp);
                }
                throw cellsid.second;
            }
        }
    }

    cells[1]->setPiece(cells[0]->getPiece());
    cells[0]->empty();
    if (move.at(5) == '1')
    {
        cells[0]->setPiece(attackp);
    }
}

void ChessBoard::checkmate(COLOR color)
{
    cout << "check\n";
    bool mate = false;
    king *k;
    vector<ID> temp;
    bool find = false;
    for (auto &i : Board)
    {
        for (auto &j : i)
        {
            if (!j.getState())
            {
                if (j.getPiece()->get_type() == KING && j.getPiece()->get_color() == color)
                {
                    k = dynamic_cast<king *>(j.getPiece());
                    k->access(j.getId(), Board);
                    find = true;
                    break;
                }
            }
        }
        if (find)
        {
            break;
        }
    }
    if (k->get_possiblemoves().size() != 0)
    {
        return;
    }
    if (k->get_threat().size() != 0)
    {
        return;
    }
    //cout << "kish ref " << k->kishr << endl;
    auto kishpath = k->get_kishpath();
    for (auto &i : kishpath)
    {
        for (auto &n : Board)
        {
            for (auto &j : n)
            {
                if (j.getPiece() != nullptr)
                {
                    if (k->get_color() == j.getPiece()->get_color())
                    {
                        j.getPiece()->access(j.getId(), Board);
                        temp = j.getPiece()->get_possiblemoves();
                        sort(temp.begin(), temp.end());
                        if (binary_search(temp.cbegin(), temp.cend(), i))
                        {
                            cout << "in mate  " << i << j.getPiece()->get_type() << endl;
                            return;
                        }
                        temp = j.getPiece()->get_threat();
                        sort(temp.begin(), temp.end());
                        if (binary_search(temp.cbegin(), temp.cend(), k->kishr))
                        {
                            cout << "in mate  " << k->kishr << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    throw matexcept(" and kish");
}
