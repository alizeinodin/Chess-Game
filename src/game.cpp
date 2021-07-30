#include "game.h"
#include "player.h"
using namespace std;

<<<<<<< HEAD
Game &Game::getInstance(Name name)
{
    static Game game(name);
    return game;
}

Game::Game(Name name) : gamename(name) {}


=======
Game::Game(Name name) : gamename(name) {}


>>>>>>> 87196fc2639f971ed2f33db757835bb516348ed2
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

void Game::order(MOVE move)
{
    Cell cell = gameBoard.search(cut_str(move).first);
    if (Turn)
    {
        if (cell.getPiece()->get_color() == player1->getcolor())
        {
            cell = gameBoard.search(cut_str(move).second);
            if (cell.getState())
            {
                gameBoard.movePiece(move);
                Turn = false;
            }
            else
            {
                gameBoard.attack(move);
            }
        }
        throw invalid_argument("can not move this piece");
    }
    else
    {
        if (cell.getPiece()->get_color() == player2->getcolor())
        {
            cell = gameBoard.search(cut_str(move).second);
            if (cell.getState())
            {
                gameBoard.movePiece(move);
                Turn = true;
            }
            else
            {
                gameBoard.attack(move);
            }
        }
        throw invalid_argument("can not move this piece");
    }
}

void Game::startgame()
{
    gameBoard.startboard();
}