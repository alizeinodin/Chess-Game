#include "include/game.h"
#include "include/player.h"
using namespace std;

Game::Game(Name name) : gamename(name) {}

Game &Game::getInstance(Name name)
{
    static Game game(name);
    return game;
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
        return *player2;
    }
    throw invalid_argument("invalid color");
}

void Game::order(MOVE move)
{
    Cell cell = gameBoard.search(cut_str(move).first);
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
                move += "P1";
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
                move += "P1";
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
                move += "P2";
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
                move += "P2";
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
    string move;
    Cell cells[2];
    ChessMan * temp;
    if (Turn)
    {
        move = moves.back();
        if (move.at(7) == '2')
        {
            cells[0] = gameBoard.search(cut_str(move).second);
            cells[1] = gameBoard.search(cut_str(move).first);
            if (move.at(5) == '0')
            {
                temp = cells[0].getPiece();
                cells[0].empty();
                cells[1].setPiece(temp);
                moves.pop_back();
                Turn = false;
                return;
            }
            else
            {
                temp = cells[0].getPiece();
                cells[0].empty();
                cells[1].setPiece(temp);
                cells[1].setPiece(player2->last_piece());
                moves.pop_back();
                Turn = false;
                return;
            }
             
        }
    }
    else
    {
        move = moves.back();
        if (move.at(7) == '1')
        {
            cells[0] = gameBoard.search(cut_str(move).second);
            cells[1] = gameBoard.search(cut_str(move).first);
            if (move.at(5) == '0')
            {
                temp = cells[0].getPiece();
                cells[0].empty();
                cells[1].setPiece(temp);
                moves.pop_back();
                Turn = true;
                return;
            }
            else
            {
                temp = cells[0].getPiece();
                cells[0].empty();
                cells[1].setPiece(temp);
                cells[1].setPiece(player1->last_piece());
                moves.pop_back();
                Turn = true;
                return;
            }
        }
    }
}
