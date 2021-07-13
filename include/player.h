#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>


using ID = unsigned int;
using Name = std::string;
using Score = int;

class player
{
    private:
    ID id;
    Name name;
    Score PScore = 0; // positive socre
    Score NScore = 0; // negative score


    public:
    player(Name);
    void addScore(size_t state, int score); // add score to p of n score
    
};

#endif /* _PLAYER_H */
