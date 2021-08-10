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
    virtual void move(MOVE, std::array<std::array<Cell, 8>, 8> &board);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board); // threat with cell ID and score
    virtual ChessMan  * attack(std::string, Cell **);
    virtual ID get_random(ID);
    
};

#endif /* _KNIGHT_H */
