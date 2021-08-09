#include "../include/game.h"
#include "../include/player.h"
#include "../include/enpassantexcept.h"
#include "../include/pawnpromotion.h"
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
    string saveMove = move;
    transform(move.begin(), move.end(), move.begin(), ::toupper);
    Cell cell = gameBoard.search(cut_str(move).first);
    cerr << move << endl;
    cout << "w:" << boolalpha << player1->iskish() << "\tb:" << player2->iskish() << endl;
    if (Turn)
    {
        if (cell.getPiece() != nullptr)
        {
            //cout << cell.getPiece()->get_color();
            if (cell.getPiece()->get_color() == player1->getcolor())
            {
                if (player1->getScore(0))
                {
                    gameBoard.randommoves(player1->getcolor());
                    player1->addScore(0, -15);
                }

                if (!player1->iskish())
                {
                    saveMove = string("P1") + saveMove; // player1 moved piece
                    cell = gameBoard.search(cut_str(move).second);
                    if (cell.getState())
                    {

                        cerr << "start move piece" << endl;
                        try
                        {
                            gameBoard.movePiece(move); //move   isn't  kish   p1
                            saveMove += "0";
                            move += "0";
                        }
                        catch (enpassantexcept &e)
                        {
                            try
                            {
                                move += "1";
                                gameBoard.threat(player2->getcolor());
                            }
                            catch (const kishexcept &er)
                            {
                                gameBoard.undo(move, e.attack);
                                throw invalid_argument("this piece is pinned!");
                            }
                            ID q = e.id;
                            cout << "enpassant\n";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            saveMove += "1";
                            saveMove.at(5) = q.at(0);
                            saveMove.at(6) = q.at(1);
                            moves.push_back(saveMove);
                            Turn = false;
                            throw e;
                        }
                        catch (pawnpromotion &e)
                        {
                            try
                            {
                                move += "0";
                                gameBoard.threat(player2->getcolor());
                            }
                            catch (const kishexcept &e)
                            {
                                gameBoard.undo(move, nullptr);
                                throw invalid_argument("this piece is pinned!");
                            }
                            saveMove += "0";
                            moves.push_back(saveMove);
                            Turn = false;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player2->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, nullptr);
                            throw invalid_argument("this piece is pinned!");
                        }
                        cout << "end move piece" << endl;
                        saveMove += "0";
                        moves.push_back(saveMove);
                        Turn = false;
                        return;
                    }
                    else
                    {
                        try
                        {
                            attackpiece = gameBoard.attack(move); //attack isn't  kish p1
                            saveMove += "1";
                            move += "1";
                        }
                        catch (pawnpromotion &e)
                        {
                            saveMove += "1";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player2->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, attackpiece);
                            throw invalid_argument("you have kish can't this move!");
                        }
                    }
                    moves.push_back(saveMove);
                    Turn = false;
                    return;
                }
                else
                {
                    saveMove = string("P1") + saveMove; // player1 moved piece
                    cell = gameBoard.search(cut_str(move).second);
                    if (cell.getState())
                    {
                        cerr << "start move piece" << endl;
                        try
                        {
                            gameBoard.movePiece(move); //move   is   kish   p1
                            saveMove += "0";
                            move += "0";
                        }
                        catch (enpassantexcept &e)
                        {
                            try
                            {
                                move += "1";
                                gameBoard.threat(player2->getcolor());
                                cout << "try\n";
                            }
                            catch (const kishexcept &er)
                            {
                                cout << "catch\n";
                                gameBoard.undo(move, e.attack);
                                throw invalid_argument("you have kish can't this move!");
                            }
                            ID q = e.id;
                            cout << "enpassant\n";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            saveMove += "1";
                            saveMove.at(5) = q.at(0);
                            saveMove.at(6) = q.at(1);
                            moves.push_back(saveMove);
                            Turn = false;
                            throw e;
                        }
                        catch (pawnpromotion &e)
                        {
                            try
                            {
                                move += "0";
                                gameBoard.threat(player2->getcolor());
                                cout << "try\n";
                            }
                            catch (const kishexcept &er)
                            {
                                cout << "catch\n";
                                gameBoard.undo(move, nullptr);
                                throw invalid_argument("you have kish can't this move!");
                            }
                            saveMove += "0";
                            moves.push_back(saveMove);
                            Turn = false;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player2->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, nullptr);
                            throw invalid_argument("you have kish can't this move!");
                        }

                        cout << "end move piece" << endl;
                        moves.push_back(saveMove);
                        Turn = false;
                        return;
                    }
                    else
                    {
                        try
                        {
                            attackpiece = gameBoard.attack(move); // attack is kish p1
                            saveMove += "1";
                            move += "1";
                        }
                        catch (pawnpromotion &e)
                        {
                            try
                            {
                                move += "1";
                                gameBoard.threat(player2->getcolor());
                                cout << "try\n";
                            }
                            catch (const kishexcept &e)
                            {
                                cout << "catch\n";
                                gameBoard.undo(move, attackpiece);
                                throw invalid_argument("you have kish can't this move!");
                            }
                            saveMove += "1";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            moves.push_back(saveMove);
                            Turn = false;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player2->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, attackpiece);
                            attackpiece = nullptr;
                            throw invalid_argument("you have kish can't this attack!");
                        }
                    }
                    moves.push_back(saveMove);
                    Turn = false;
                    return;
                }
            }
            throw invalid_argument("It isn't your turn!");
        }
        throw invalid_argument("piece not exist!");
    }
    else
    {
        if (cell.getPiece() != nullptr)
        {
            if (cell.getPiece()->get_color() == player2->getcolor())
            {
                if (!player2->iskish())
                {
                    saveMove = string("P2") + saveMove; // player2 moved piece
                    cell = gameBoard.search(cut_str(move).second);
                    if (cell.getState())
                    {
                        cerr << "start move piece" << endl;
                        try
                        {
                            gameBoard.movePiece(move); // movepiece  isn't   kish  p2
                            move += "0";
                            saveMove += "0";
                        }
                        catch (enpassantexcept &e)
                        {
                            try
                            {
                                move += "1";
                                cout << "try pin\n";
                                gameBoard.threat(player1->getcolor());
                            }
                            catch (const kishexcept &err)
                            {
                                gameBoard.undo(move, e.attack);
                                throw invalid_argument("this piece is pinned!");
                            }
                            ID q = e.id;
                            cout << "enpassant\n";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            saveMove += "1";
                            saveMove.at(5) = q.at(0);
                            saveMove.at(6) = q.at(1);
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        catch (pawnpromotion &e)
                        {
                            try
                            {
                                move += "0";
                                cout << "try pin\n";
                                gameBoard.threat(player1->getcolor());
                            }
                            catch (const kishexcept &e)
                            {
                                gameBoard.undo(move, nullptr);
                                throw invalid_argument("this piece is pinned!");
                            }
                            saveMove += "0";
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        try
                        {
                            cout << "try pin\n";
                            gameBoard.threat(player1->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, nullptr);
                            throw invalid_argument("this piece is pinned!");
                        }
                        cout << "end move piece" << endl;
                        moves.push_back(saveMove);
                        Turn = true;
                        return;
                    }
                    else
                    {
                        try
                        {
                            attackpiece = gameBoard.attack(move); //attack   isn't  kish   p2
                            saveMove += "1";
                            move += "1";
                        }
                        catch (pawnpromotion &e)
                        {
                            saveMove += "1";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player1->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, attackpiece);
                            throw invalid_argument("this piece is pinned!");
                        }
                    }
                    moves.push_back(saveMove);
                    Turn = true;
                    return;
                }
                else
                {
                    saveMove = string("P2") + saveMove; // player1 moved piece
                    cell = gameBoard.search(cut_str(move).second);
                    if (cell.getState())
                    {
                        cerr << "start move piece" << endl;
                        try
                        {
                            gameBoard.movePiece(move); //movepiece  is  kish  p2
                            saveMove += "0";
                            move += "0";
                        }
                        catch (enpassantexcept &e)
                        {
                            try
                            {
                                move += "1";
                                gameBoard.threat(player1->getcolor());
                                cout << "try\n";
                            }
                            catch (const kishexcept &r)
                            {
                                cout << "catch\n";
                                gameBoard.undo(move, e.attack);
                                throw invalid_argument("you have kish can't this move!");
                            }
                            ID q = e.id;
                            cout << "enpassant\n";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            saveMove += "1";
                            saveMove.at(5) = q.at(0);
                            saveMove.at(6) = q.at(1);
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        catch (pawnpromotion &e)
                        {
                            try
                            {
                                move += "0";
                                gameBoard.threat(player1->getcolor());
                                cout << "try\n";
                            }
                            catch (const kishexcept &e)
                            {
                                cout << "catch\n";
                                gameBoard.undo(move, nullptr);
                                throw invalid_argument("you have kish can't this move!");
                            }
                            saveMove += "0";
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player1->getcolor());
                            cout << "try\n";
                        }
                        catch (const kishexcept &e)
                        {
                            cout << "catch\n";
                            gameBoard.undo(move, nullptr);
                            throw invalid_argument("you have kish can't this move!");
                        }

                        cout << "end move piece" << endl;
                        moves.push_back(saveMove);
                        Turn = true;
                        return;
                    }
                    else
                    {
                        try
                        {
                            attackpiece = gameBoard.attack(move); //attack is  kish  p2
                            saveMove += "1";
                            move += "1";
                        }
                        catch (pawnpromotion &e)
                        {
                            try
                            {
                                move += "1";
                                gameBoard.threat(player1->getcolor());
                                cout << "try\n";
                            }
                            catch (const kishexcept &e)
                            {

                                cout << "catch\n";
                                gameBoard.undo(move, attackpiece);
                                throw invalid_argument("you have kish can't this move!");
                            }
                            saveMove += "1";
                            attackpiece = e.attack;
                            e.attack = nullptr;
                            moves.push_back(saveMove);
                            Turn = true;
                            throw e;
                        }
                        try
                        {
                            gameBoard.threat(player1->getcolor());
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, attackpiece);
                            attackpiece = nullptr;
                            throw invalid_argument("you have kish can't this move!");
                        }
                    }
                    moves.push_back(saveMove);
                    Turn = true;
                    return;
                }
            }
            throw invalid_argument("It is not your turn!");
        }
        throw invalid_argument("piece not exist!");
    }
}

void Game::startgame()
{
    gameBoard.startboard();
}

QString Game::undo()
{
    string move = moves.back();
    string tempscore;
    // find last move of player
    // this code is for exist two move option in program
    string temp = move.substr(2, 6);
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    if (move.at(1) == '2')
    {
        gameBoard.undo(temp, player2->get_last_attack());
        player2->addScore(0, 5);
        tempscore.append(move.begin() + 8, move.end());
        //cout << "sc " << *(move.begin() + 8) << endl << tempscore << endl;
        player2->addScore(1, -stoi(tempscore));
        Turn = false;
        moves.pop_back();
    }
    else if (move.at(1) == '1')
    {
        gameBoard.undo(temp, player1->get_last_attack());
        player1->addScore(0, 5);
        tempscore.append(move.begin() + 8, move.end());
        //cout << "sc " << *(move.begin() + 8) << endl << tempscore << endl;
        player1->addScore(1, -stoi(tempscore));
        Turn = true;
        moves.pop_back();
    }
    temp = move.substr(2, 5);
    cout << "move undo: " << temp << endl;
    string makeResult = temp[0] + temp.substr(3, 4) + temp.substr(1, 2);
    cout << "make result: " << makeResult << endl;
    QString result = QString::fromStdString(makeResult);
    return result;
}

std::vector<MOVE> Game::movesUndo()
{
    return moves;
}

void Game::update_score()
{
    int score = 0;
    int temp = 0;
    if (Turn)
    {
        if (attackpiece != nullptr)
        {
            switch (attackpiece->get_type())
            {
            case QUEEN:
                score += 15;
                break;
            case ROOK:
            case BISHOP:
            case KNIGHT:
                score += 8;
                break;
            case PAWN:
                score += 3;
                break;
            }
            player2->addScore(1, score);
            player2->add_attack_piece(attackpiece);
        }
        try
        {
            temp = gameBoard.threat(player2->getcolor());
            player2->addScore(1, temp);
            score += temp;
            string t = to_string(score);
            moves.rbegin()->append(t);
        }
        catch (const kishexcept &e)
        {
            player1->setkish(true);
            try
            {
                gameBoard.checkmate(player1->getcolor());
            }
            catch (const matexcept &e)
            {
                player2->addScore(1, 70);
                score += 70;
                string t = to_string(score);
                moves.rbegin()->append(t);
                throw e;
            }
            player2->addScore(1, 10);
            score += 10;
            string t = to_string(score);
            moves.rbegin()->append(t);
            throw e;
        }
        if (player1->iskish())
        {
            player1->setkish(false);
        }
    }
    else
    {
        if (attackpiece != nullptr)
        {
            switch (attackpiece->get_type())
            {
            case QUEEN:
                score += 15;
                break;
            case ROOK:
            case BISHOP:
            case KNIGHT:
                score += 8;
                break;
            case PAWN:
                score += 3;
                break;
            }
            player1->addScore(1, score);
            player1->add_attack_piece(attackpiece);
        }
        try
        {
            temp = gameBoard.threat(player1->getcolor());
            player1->addScore(1, temp);
            score += temp;
            string t = to_string(score);
            moves.rbegin()->append(t);
        }
        catch (const kishexcept &e)
        {
            cout << "kish catch w\n";
            player2->setkish(true);
            try
            {
                gameBoard.checkmate(player1->getcolor());
            }
            catch (const matexcept &er)
            {
                player1->addScore(1, 70);
                score += 70;
                string t = to_string(score);
                moves.rbegin()->append(t);
                throw er;
            }
            player1->addScore(1, 10);
            score += 10;
            string t = to_string(score);
            moves.rbegin()->append(t);
            throw e;
        }
        if (player2->iskish())
        {
            player2->setkish(false);
        }
    }
}

Player &Game::compareScore()
{
    if (player1->getScore(1) > player2->getScore(1))
    {
        return *player1;
    }
    else if (player1->getScore(1) < player2->getScore(1))
    {
        return *player2;
    }
    else
    {
        throw Equality();
    }
}

void Game::restart()
{
    player1->restartScore();
    player2->restartScore();
}

void Game::promotion(ID pawncell, piece typepiece)
{
    ChessMan *temppiece;
    Cell *temp = &gameBoard.search(pawncell);
    switch (typepiece)
    {
    case QUEEN:
        temppiece = new queen(temp->getPiece()->get_color());
        break;
    case ROOK:
        temppiece = new rook(temp->getPiece()->get_color());
        break;
    case BISHOP:
        temppiece = new bishop(temp->getPiece()->get_color());
        break;
    case KNIGHT:
        temppiece = new knight(temp->getPiece()->get_color());
        break;
    case PAWN:
        temppiece = new pawn(temp->getPiece()->get_color());
        break;
    default:
        throw invalid_argument("piece type invalid");
        break;
    }
    ChessMan *chess = temp->getPiece();
    delete chess;
    temp->setPiece(temppiece);
}


void Game::twomove(MOVE move)
{
    try
    {
        this->order(move);
        if (Trun)
        {
            Turn = false;
        }
        else
        {
            Turn = true;   
        }
    }
    catch(const std::exception& e)
    {
        if (Trun)
        {
            Turn = false;
        }
        else
        {
            Turn = true;   
        }
        throw e;
    }
    
}