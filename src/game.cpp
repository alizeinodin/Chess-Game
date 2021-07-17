#include "game.h"
using namespace std;

ChessBoard &Game::getBoard()
{
    return gameBoard;
}

void Game::setPlayer(size_t num, string name)
{
    switch (num)
    {
    case 1:
        player1 = new Player(name);
        break;
    case 2:
        player2 = new Player(name);
        
        break;

    default:
        throw invalid_argument("ERROR: invalid num in setPlayer");
        break;
    }
}