#ifndef _KING_H
#define _KING_H
#include "chessMan.h"
#include <iostream>
#include <array>
#include "using.h"
#include "cell.h"

class king : public ChessMan
{
public:
    king(COLOR);
    virtual void move(MOVE, std::array<std::array<Cell, 8>, 8> &board);
    virtual void access(std::string origin, std::array<std::array<Cell, 8>, 8> &board); // cheking access for cell's
    virtual std::map<std::string, int> threat(std::string, std::array<std::array<Cell, 8>, 8> &board); // threat with cell ID and score
    virtual ChessMan  * attack(std::string, Cell **);
    void castling(std::string, std::array<std::array<Cell, 8>, 8> &board);
    void insert(std::vector<ID>&);
    bool getmate() {return ismate;}
    std::vector<ID>& get_kishpath();
    ID kishr;

    private: 
    std::vector<ID> kishpath;
    bool ismate = false;
    
};

#endif /* _KING_H */
