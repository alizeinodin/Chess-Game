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
    virtual void movePiece(MOVE, std::array<std::array<Cell, 8>, 8> &board);
    virtual bool access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board); // threat with cell ID and score
    virtual int attack(std::string, Cell &);
    
};

#endif /* _KNIGHT_H */
