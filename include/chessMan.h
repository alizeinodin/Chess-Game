#include "using.h"
#include "moving.h"
#include "kishexcept.h"
#include <array>
#include <map>
#ifndef _CHESSMAN_H
#define _CHESSMAN_H

//#include <map>
enum piece {KING, QUEEN, ROOK, BISHOP, KNIGHT, POWN};
class Cell;
class ChessMan
{
protected:
    piece piecetype;
    State CurrentState;
    State TypeMove;
    COLOR color;
    vector<std::string> threat_id;
    

public:
    ChessMan(COLOR);
    virtual bool access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board) = 0; // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, array<array<Cell, 8>, 8> &board) = 0; // threat with cell ID and score
    virtual int attack(std::string, Cell &) = 0;
    virtual void movePiece(std::string, std::array<std::array<Cell, 8>, 8> &board) = 0;
    COLOR get_color();
    piece get_type();
};

#endif /* _CHESSMAN_H */
