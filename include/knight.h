#ifndef _KNIGHT_H
#define _KNIGHT_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class knight : public ChessMan
{
public:
    virtual void movePiece(MOVE);
    virtual bool access(std::string); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string); // threat with cell ID and score
    virtual void attack(std::string);
};

#endif /* _KNIGHT_H */
