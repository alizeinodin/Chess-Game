#ifndef _KING_H
#define _KING_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class king : public ChessMan
{
public:
    king(COLOR);
    virtual void movePiece(MOVE);
    virtual bool access(std::string); // cheking access for cell's
    //virtual std::map<std::string, int> threat(std::string); // threat with cell ID and score
    //virtual void attack(std::string);
};

#endif /* _KING_H */
