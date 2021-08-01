#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
#include <stdexcept>
#include <vector>
#include "chessMan.h"

using PID = std::string;
using Name = std::string;
using Score = int;
using COLOR = std::string;

class Player
{
    private:
    PID id;
    Name name;
    Score PScore = 0; // positive socre
    Score NScore = 0; // negative score
    COLOR color;
    std::vector<ChessMan *> attackpiece;


    public:
    Player(Name, COLOR);
    void addScore(size_t state, int score); // add score to p of n score
    Score getScore(size_t); 
    COLOR getcolor();
    void add_attack_piece(ChessMan *);
};

#endif /* _PLAYER_H */
