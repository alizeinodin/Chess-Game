#ifndef _QUEEN_H
#define _QUEEN_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class queen : public ChessMan
{
public:
    queen(COLOR);
    virtual void movePiece(MOVE);
    virtual bool access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string); // threat with cell ID and score
    virtual void attack(std::string);
};

#endif /* _QUEEN_H */
