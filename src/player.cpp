#include "include/player.h"
#include "include/chessMan.h"
#include <stdexcept>
using namespace std;

Player::Player(Name name, COLOR color)
{
    this->name = name;
    this->color = color;
    
}

void Player::restartScore()
{
    PScore = 0;
    NScore = 0;
}

void Player::addScore(size_t state, int score)
{
    switch (state)
    {
    case 1:
        PScore += score;
        break;
    case 0:
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

    case 0:
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


void Player::add_attack_piece(ChessMan * attack)
{
    attackpiece.push_back(attack);
}


ChessMan * Player::get_last_attack()
{
    if (attackpiece.size() != 0)
    {
        ChessMan *temp = attackpiece.back();
        attackpiece.pop_back();
        return temp;
    }
    return nullptr;
}

void Player:: setkish(bool k)
{
    kish = k;
}
bool Player::iskish()
{
    return kish;
}


void Player:: addporomotion(ChessMan * t)
{
    poromotion.push_back(t);
}

pawn * Player:: getporomotion()
{
    if (poromotion.size() != 0)
    {
        ChessMan * t = poromotion.back();

        poromotion.pop_back();
        return dynamic_cast<pawn *> (t);
    }
    return nullptr;
}

Name Player:: get_name()
{
    return name;
}