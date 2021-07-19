#ifndef _KNIGHT_H
#define _KNIGHT_H
#include "chessMan.h"
#include "cell.h"
#include <array>
#include <iostream>
#include "using.h"

class knight : public ChessMan
{
public:
    knight(COLOR);
    virtual void movePiece(MOVE);
    virtual bool access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    //virtual std::map<std::string, int> threat(std::string); // threat with cell ID and score
   // virtual void attack(std::string);
    
};

#endif /* _KNIGHT_H */
