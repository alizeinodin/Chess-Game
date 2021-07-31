#include "include/game.h"
#include "include/player.h"
#include <QDebug>
using namespace std;

Game::Game(Name name) : gamename(name) {}

//Game &Game::getInstance(Name name)
//{
//    static Game game(name);
//    return game;
//}
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
        return *player2;
    }
    throw invalid_argument("invalid color");
}

void Game::order(MOVE move)
{
//    cout << cut_str(move).first << endl;
    Cell cell = gameBoard.search(cut_str(move).first);
    std::cerr << cell.getId() << std::endl;
    ChessMan *attackpiece = nullptr;
    int score = 0;
    if (Turn)
    {
        if (cell.getPiece()->get_color() == player1->getcolor())
        {
            cell = gameBoard.search(cut_str(move).second);
            if (cell.getState())
            {
                gameBoard.movePiece(move);
                move += "0";
                moves.push_back(move);
                Turn = false;
            }
            else
            {
                attackpiece = gameBoard.attack(move);
            }
            player1->addScore(1, gameBoard.threat(player1->getcolor()));
            if (attackpiece != nullptr)
            {
                switch (attackpiece->get_type())
                {
                case QUEEN:
                    score += 15;
                    move += "1";
                    break;
                case ROOK:
                case BISHOP:
                case KNIGHT:
                    score += 8;
                    move += "1";
                    break;
                case POWN:
                    score += 3;
                    move += "1";
                    break;
                }
                moves.push_back(move);
                player1->addScore(1, score);
                player1->add_attack_piece(attackpiece);
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
                move += "0";
                moves.push_back(move);
                Turn = true;
            }
            else
            {
                attackpiece = gameBoard.attack(move);
            }
            player2->addScore(1, gameBoard.threat(player2->getcolor()));

            if (attackpiece != nullptr)
            {
                switch (attackpiece->get_type())
                {
                case QUEEN:
                    score += 15;
                    move += "1";
                    break;
                case ROOK:
                case BISHOP:
                case KNIGHT:
                    score += 8;
                    move += "1";
                    break;
                case POWN:
                    score += 3;
                    move += "1";
                    break;
                }
                moves.push_back(move);
                player2->addScore(1, score);
                player2->add_attack_piece(attackpiece);
            }
        }
        throw invalid_argument("can not move this piece");
    }
}

void Game::startgame()
{
    gameBoard.startboard();
}

void Game::undo()
{
    
}
