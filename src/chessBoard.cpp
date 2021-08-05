#include "../include/chessBoard.h"
#include "../include/chessMan.h"
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
        } else
        if (i.getId().at(0) == 'B' || i.getId().at(0) == 'G')
        {
            ChessMan *piece = new knight("Black");
            i.setPiece(piece);
        } else
        if (i.getId().at(0) == 'C' || i.getId().at(0) == 'F')
        {
            ChessMan *piece = new bishop("Black");
            i.setPiece(piece);
        } else
        if (i.getId().at(0) == 'D')
        {
            ChessMan *piece = new queen("Black");
            i.setPiece(piece);
        } else
        if (i.getId().at(0) == 'E')
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
    cellid += origin.substr(0, 1);
    cellid += Board.at(rndcell[0]).at(rndcell[1]).getId();
    this->movePiece(cellid);
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
    throw invalid_argument("3cell is empty");
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
        return temp->attack(move, *cells[1]);
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


void ChessBoard::undo(MOVE move, ChessMan * attackp)
{
    auto cellsid = cut_str(move);
    Cell * cells[2];
    cells[0] = search_cell(cellsid.second, Board);
    cells[1] = search_cell(cellsid.first, Board);
    ChessMan * temp = cells[1]->getPiece();
    cells[0]->empty();
    cells[1]->setPiece(temp);
    if (move.at(5) == '1')
    {
        cells[0]->setPiece(attackp);
    }
}
