#include "using.h"
#include "moving.h"
#include "kishexcept.h"
#include <array>
#include <vector>
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
    std::vector<std::string> threat_id;
    std::vector<Cell> possible;
    ChessMan * attackpiece = nullptr;
    int attackscore;
    

public:
    ChessMan(COLOR);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board) = 0; // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board) = 0; // threat with cell ID and score
    virtual void attack(std::string, Cell &) = 0;
    virtual void movePiece(std::string, std::array<std::array<Cell, 8>, 8> &board) = 0;
    COLOR get_color();
    piece get_type();
    std::vector<Cell> get_possiblemoves();
    ChessMan * get_attackpiece();
    int get_attackscore();
};

#endif /* _CHESSMAN_H */
