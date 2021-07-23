#include "game.h"
using namespace std;
Game &Game::getInstance()
{
    static Game game;
    return game;
}

Game::Game()
{
}

ChessBoard &Game::getBoard()
{
    return gameBoard;
}

void Game::setPlayer(size_t num, string name)
{
    switch (num)
    {
    case 1:
        player1 = new Player(name, string("white"));
        break;
    case 2:
<<<<<<< HEAD
        player2 = new Player(name, string("black"));
=======
        player2 = new Player(name);
>>>>>>> 36e7c21c7b390f60cacad6e391ec170dee253fdb

        break;

    default:
        throw invalid_argument("ERROR: invalid num in setPlayer");
        break;
    }
}