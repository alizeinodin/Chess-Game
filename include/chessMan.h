#include "using.h"
#include "moving.h"
#include "cell.h"
#include "kishexcept.h"
#include <array>
#include <vector>
#include <map>
#ifndef _CHESSMAN_H
#define _CHESSMAN_H
enum piece {KING, QUEEN, ROOK, BISHOP, KNIGHT, POWN};
class ChessMan
{
protected:
    piece piecetype;
    State CurrentState;
    State TypeMove;
    COLOR color;
    std::vector<std::string> threat_id;
    std::vector<Cell> possible;
    

public:
    ChessMan(COLOR);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board) = 0; // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board) = 0; // threat with cell ID and score
    virtual ChessMan  * attack(std::string, Cell &) = 0;
    virtual void move(std::string, std::array<std::array<Cell, 8>, 8> &board) = 0;
    COLOR get_color();
    piece get_type();
    std::vector<Cell> get_possiblemoves();
};

#endif /* _CHESSMAN_H */
