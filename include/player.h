#include <QString>
#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
#include <stdexcept>
#include <vector>
#include "chessMan.h"
#include "pawn.h"

using PID = std::string;
using Name = QString;
using Score = int;
using COLOR = std::string;

class Player
{
    private:
    bool kish = false;
    PID id;
    Name name;
    Score PScore = 0; // positive socre
    Score NScore = 0; // negative score
    COLOR color;
    std::vector<ChessMan *> attackpiece;
    std::vector<ChessMan *> poromotion;


    public:
    Player(Name, COLOR);
    void restartScore();
    void addScore(size_t state, int score); // add score to p of n score
    Score getScore(size_t); 
    COLOR getcolor();
    void add_attack_piece(ChessMan *);
    ChessMan * get_last_attack();
    void setkish(bool);
    bool iskish();
    void addporomotion(ChessMan *);
    pawn * getporomotion();
};

#endif /* _PLAYER_H */
