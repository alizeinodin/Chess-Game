#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
#include <stdexcept>


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


    public:
    Player(Name, COLOR);
    void addScore(size_t state, int score); // add score to p of n score
    Score getScore(size_t); 
    
};

#endif /* _PLAYER_H */
