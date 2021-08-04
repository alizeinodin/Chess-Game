#include "../include/game.h"
#include "../include/player.h"
#include <QDebug>
using namespace std;

Game::Game(Name name) : gamename(name) {}

//Game &Game::getInstance(Name name)
//{
//    static Game game(name);
//    return game;
//}
void Game::setPlayer(Color color, QString name)
{
    switch (color)
    {
    case WHITE:
        player1 = new Player(name, string("White"));
        break;
    case BLACK:
        player2 = new Player(name, string("Black"));

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
    transform(move.begin(), move.end(), move.begin(), ::toupper);
    Cell cell = gameBoard.search(cut_str(move).first);
    ChessMan *attackpiece = nullptr;
    cerr << move << endl;
    int score = 0;
    if (Turn)
    {
        if (cell.getPiece() != nullptr)
        {
            cout << cell.getPiece()->get_color();
            if (cell.getPiece()->get_color() == player1->getcolor())
            {
                cell = gameBoard.search(cut_str(move).second);
                if (cell.getState())
                {
                    cerr << "start move piece" << endl;
                    gameBoard.movePiece(move);
                    cout << "end move piece" << endl;
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
                return;
            }
            throw invalid_argument("can not move this piece");
        }
        throw invalid_argument("piece not exist");
    }
    else
    {
        if (cell.getPiece() != nullptr)
        {
            if (cell.getPiece()->get_color() == player2->getcolor())
            {
                cell = gameBoard.search(cut_str(move).second);
                if (cell.getState())
                {
                    cerr << "start move piece" << endl;
                    gameBoard.movePiece(move);
                    cout << "end move piece" << endl;
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
                return;
            }
            throw invalid_argument("can not move this piece");
        }
        throw invalid_argument("piece not exist");
    }
}

void Game::startgame()
{
    gameBoard.startboard();
}

QString Game::undo()
{
}
