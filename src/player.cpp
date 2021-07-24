#include "player.h"
#include <stdexcept>
using namespace std;

Player::Player(Name name, COLOR color)
{
    this->name = name;
    this->color = color;
}

void Player::addScore(size_t state, int score)
{
    switch (state)
    {
    case 1:
        PScore += score;
        break;
    case 2:
        NScore += score;
        break;

    default:
        throw invalid_argument("ERROR: state in addScore is invalid");

        break;
    }
}

int Player::getScore(size_t state)
{
    switch (state)
    {
    case 1:
        return PScore;

        break;

    case 2:
        return NScore;

        break;

    default:
        throw invalid_argument("ERROR: state in getScore is invalid");

        break;
    }
    return 0; // compiler never arrive to this line and this is for warning
}

COLOR Player::getcolor()
{
    return color;
}