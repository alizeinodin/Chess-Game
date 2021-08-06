#include "../include/king.h"
#include "../include/util.h"
#include "../include/matexcept.h"
#include <algorithm>
#include <vector>
using namespace std;

king::king(COLOR c) : ChessMan(c)
{
    piecetype = KING;
}

void king::move(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell *cells[2];
    if (move.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    //cout << "Move King: " << boolalpha << (move.at(0) == 'K') << endl;
    if(move.at(0) == 'K')
    {
        auto cellsid = cut_str(move);
        this->access(cellsid.first, board);
        size_t i = 0;
        for (; i < possible.size(); i++)
        {
            cout << possible.at(i) << " King: " << boolalpha << (possible.at(i) == cellsid.second) <<endl;
            if (possible.at(i) == cellsid.second)
            {
                cells[0] = search_cell(cellsid.first, board);
                cells[1] = search_cell(cellsid.second, board);
                cells[1]->setPiece(cells[0]->getPiece());
                cells[0]->empty();
                return;
            }
            else if (cellsid.second == "C1" || cellsid.second == "G1" || cellsid.second == "C8" || cellsid.second == "G8")
            {
                this->castling(move, board);
                return;
            }
        }
        if (!(i < possible.size()))
        {
            throw invalid_argument("can not move!!!");
        }
        
        //throw matexcept(color);
    }
    throw invalid_argument("piece is not true");
}

void king::access(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
{
    static bool startgame_white = true;
    static bool startgame_black = true;
    if (origin.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    threat_id.clear();
    possible.clear();
    char character[] = "a";
    get_char(origin, character);
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}; // all possible moves.
    int dy[] = {1, -1, 0, -1, 1, 0, -1, 1}; // all possible moves.
    auto it = find(alfa.cbegin(), alfa.cend(), character);
    string temp;
    Cell *celltemp;
    int num = get_num(origin);
    for (size_t i = 0; i < 8; i++)
    {
        if (((num + dx[i]) <= 8) && ((num + dx[i]) > 0))
        {
            if (((it + dy[i]) < alfa.cend()) && ((it + dy[i]) >= alfa.cbegin()))
            {
                temp += (it + dy[i])->at(0);
                temp += to_string(num + dx[i]);
                //cout << origin << "\tking" << temp << endl;
            }
        }
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (celltemp->getState())
            {
                cout << !possible_move_king(temp, this->color, board) <<endl;
                if (!possible_move_king(temp, this->color, board))
                {
                    cout << temp;
                    possible.push_back(temp);
                }
                else
                {
                    cout << "ajab  " << temp << endl;
                }
                
            }
            else
            {
                threat_id.push_back(temp);
                
                temp.clear();
            }
            
            temp.clear();
        }
        temp.clear();
    }
    if (!possible.empty() && startgame_white && color == "White")
    {
        startgame_white = false;
    }
    cout << "black "<< (!possible.empty() && startgame_black && color == "Black") << endl;
    if (!possible.empty() && startgame_black && color == "Black")
    {
        startgame_black = false;
    }
    
    if (possible.empty() && !startgame_white && color == "White")
    {
        throw matexcept(color);
    }
    if (possible.empty() && !startgame_black && color == "Black")
    {
        throw matexcept(color);
    }
    

    
    
}

std::map<std::string, int> king::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
{
    bool kish = false;
    map<string, int> temp;
    this->access(cellid, board);
    for (size_t i = 0; i < threat_id.size(); i++)
    {
        if (search_cell(threat_id.at(i), board)->getPiece() != nullptr)
        {
            
            if (search_cell(threat_id.at(i), board)->getPiece()->get_color() != this->get_color())
            {
                switch (search_cell(threat_id.at(i), board)->getPiece()->get_type())
                {
                case QUEEN:
                    temp.insert(make_pair(threat_id.at(i), 5));
                    break;
                case ROOK:
                case BISHOP:
                case KNIGHT:
                    temp.insert(make_pair(threat_id.at(i), 2));
                    break;
                case PAWN:
                    temp.insert(make_pair(threat_id.at(i), 1));
                    break;
                case KING:
                    kish = true;
                    break;
                }
            }
        }
    }
    if (kish)
    {
        throw kishexcept("K");
    }
    return temp;
}

ChessMan *king::attack(std::string move, Cell &cell)
{
    ChessMan *attackpiece = cell.getPiece();
    auto temp = cut_str(move);
    if (!(attackpiece->get_color() == color) || !(attackpiece->get_color() == color))
    {
        sort(threat_id.begin(),threat_id.end());
        if (binary_search(threat_id.cbegin(), threat_id.cend(), temp.second))
        {
            cell.empty();
            cell.setPiece(this);
            return attackpiece;
        }
    }
    throw invalid_argument("can not move!!!");
    return attackpiece;
}

void king::castling(string str, std::array<std::array<Cell, 8>, 8> &board)
{
    auto temp = cut_str(str);
    bool set = true;
    string alf = "ABCDEFGH";
    string cellid;
    int i = 0;
    Cell *cells[2];

    if (color == "White")
    {
        if (get_num(temp.first) == 1)
        {
            if (temp.second == "G1")
            {
                if (search_cell("G1", board)->getState())
                {
                    bool f1 = search_cell("F1", board)->getState();

                    if (f1 && search_cell("H1", board)->getPiece()->get_type() == ROOK)
                    {
                        cells[0] = search_cell(temp.first, board);
                        cells[0]->empty();
                        cells[1] = search_cell("G1", board);
                        cells[1]->setPiece(this);
                        cells[0] = search_cell("H1", board);
                        ChessMan *chess = cells[0]->getPiece();
                        cells[0]->empty();
                        cells[1] = search_cell("F1", board);
                        cells[1]->setPiece(chess);
                        return;
                    }
                }
            }
            else if (temp.second == "C1")
            {
                if (search_cell("C1", board)->getState())
                {
                    bool b1 = search_cell("B1", board)->getState();
                    bool d1 = search_cell("D1", board)->getState();
                    if (d1 && b1 && search_cell("A1", board)->getPiece()->get_type() == ROOK)
                    {
                        cells[0] = search_cell(temp.first, board);
                        cells[0]->empty();
                        cells[1] = search_cell("C1", board);
                        cells[1]->setPiece(this);
                        cells[0] = search_cell("A1", board);
                        ChessMan *chess = cells[0]->getPiece();
                        cells[0]->empty();
                        cells[1] = search_cell("D1", board);
                        cells[1]->setPiece(chess);
                        return;
                    }
                }
            }
        }
    }
    else if (color == "Black")
    {
        if (get_num(temp.first) == 8)
        {
            if (temp.second == "G8")
            {
                if (search_cell("G8", board)->getState())
                {
                    bool f8 = search_cell("F8", board)->getState();

                    if (f8 && search_cell("H8", board)->getPiece()->get_type() == ROOK)
                    {
                        cells[0] = search_cell(temp.first, board);
                        cells[0]->empty();
                        cells[1] = search_cell("G8", board);
                        cells[1]->setPiece(this);
                        cells[0] = search_cell("H8", board);
                        ChessMan *chess = cells[0]->getPiece();
                        cells[0]->empty();
                        cells[1] = search_cell("F8", board);
                        cells[1]->setPiece(chess);
                        return;
                    }
                }
            }
            else if (temp.second == "C8")
            {
                if (search_cell("C", board)->getState())
                {
                    bool b8 = search_cell("B8", board)->getState();
                    bool d8 = search_cell("D8", board)->getState();
                    if (d8 && b8 && search_cell("A8", board)->getPiece()->get_type() == ROOK)
                    {
                        cells[0] = search_cell(temp.first, board);
                        cells[0]->empty();
                        cells[1] = search_cell("C8", board);
                        cells[1]->setPiece(this);
                        cells[0] = search_cell("A8", board);
                        ChessMan *chess = cells[0]->getPiece();
                        cells[0]->empty();
                        cells[1] = search_cell("D8", board);
                        cells[1]->setPiece(chess);
                        return;
                    }
                }
            }
        }
    }
    throw invalid_argument("can not move!!!");
}
