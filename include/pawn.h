#ifndef _PAWN_H
#define _PAWN_H
#include "chessMan.h"
#include "using.h"
#include <array>
#include "cell.h"
#include <iostream>

class pawn : public ChessMan
{
public:
    pawn(COLOR);
    virtual void movePiece(MOVE, std::array<std::array<Cell, 8>, 8> &board);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board); // threat with cell ID and score
    virtual void attack(std::string, Cell &);
    ~pawn() {}
};

#endif /* _PAWN_H */
