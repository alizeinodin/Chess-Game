#ifndef _ROOK_H
#define _ROOK_H
#include "chessMan.h"
#include "cell.h"
#include <array>
#include <iostream>
#include "using.h"

class rook : public ChessMan
{
public:
    rook(COLOR);
    virtual void movePiece(MOVE, std::array<std::array<Cell, 8>, 8> &board);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, array<array<Cell, 8>, 8> &board); // threat with cell ID and score
    virtual void attack(std::string, Cell &);
};

#endif /* _ROOK_H */