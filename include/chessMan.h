#ifndef _CHESSMAN_H
#define _CHESSMAN_H
#include <iostream>
#include "using.h"
#include "moving.h"
#include <map>

class ChessMan
{
protected:
    State CurrentState;
    State TypeMove;
    COLOR color;

public:
    ChessMan(COLOR);
    virtual bool access(std::string); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string); // threat with cell ID and score
    virtual void attack(std::string);
    virtual void movePiece(std::string);
    virtual ~ChessMan() = 0;
};

#endif /* _CHESSMAN_H */
