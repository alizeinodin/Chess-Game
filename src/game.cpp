#include "game.h"
#include "player.h"
using namespace std;

ChessBoard &Game::getBoard()
{
    return gameBoard;
}

void Game::setPlayer(Color color, string name)
{
    switch (color)
    {
    case WITHE:
        player1 = new Player(name, "#ffffff");
        break;
    case BLACK:
        player2 = new Player(name, "#000000");

        break;

    default:
        throw invalid_argument("ERROR: invalid num in setPlayer");
        break;
    }
}

Player Game::getPlayer(COLOR c)
{
    if (player1->getcolor() == c)
    {
        return *player1;
    }
    else if (player2->getcolor() == c)
    {
        return * player2;
    }
    throw invalid_argument("invalid color");
}