#ifndef _ROOK_H
#define _ROOK_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class rook : public ChessMan
{
public:
    virtual void movePiece(MOVE);
    virtual bool access(std::string); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string); // threat with cell ID and score
    virtual void attack(std::string);
};

#endif /* _ROOK_H */