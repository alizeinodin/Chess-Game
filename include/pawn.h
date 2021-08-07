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
    virtual void move(MOVE, std::array<std::array<Cell, 8>, 8> &board);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board); // threat with cell ID and score
    virtual ChessMan  * attack(std::string, Cell **);
    std::vector<ID> get_kingcantmove();

    private:
    std::vector<ID> kingcantmove;
};

#endif /* _PAWN_H */
