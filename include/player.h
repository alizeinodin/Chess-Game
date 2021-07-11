#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>

using Name = std::string;
using ID = std::string;

class Player
{
    private:
        ID id;
        Name name;
        int PScore = 0; // positive score
        int NScore = 0; // negative score

    public:
        Player(Name);
        void addScore(size_t state, int score); // add negative or positive score for player
};

#endif /* _PLAYER_H */
