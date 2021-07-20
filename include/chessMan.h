#include "using.h"
#include "moving.h"
#include <array>
#ifndef _CHESSMAN_H
#define _CHESSMAN_H

//#include <map>
class Cell;
class ChessMan
{
protected:
    State CurrentState;
    State TypeMove;
    COLOR color;
    

public:
    ChessMan(COLOR);
    virtual bool access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board) = 0; // cheking access for cell's
    //virtual std::map<std::string, int> threat(std::string) = 0; // threat with cell ID and score
    virtual int attack(std::string, Cell &) = 0;
    virtual void movePiece(std::string, std::array<std::array<Cell, 8>, 8> &board) = 0;
    COLOR get_color();
};

#endif /* _CHESSMAN_H */
