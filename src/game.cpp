#include "../include/game.h"
#include "../include/player.h"
#include "../include/enpassantexcept.h"
#include "../include/pawnpromotion.h"
#include "../include/undoattack.h"
#include "../include/promotionundo.h"
#include "../include/castling.h"
#include <algorithm>
#include <string>
#include <sstream>
#include <QDebug>
using namespace std;

Game::Game(Name name) : gamename(name) {}

//Game &Game::getInstance(Name name)
//{
//    static Game game(name);
//    return game;
//}

// ---------------

//  set player for game
// ---------------
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
// ---------------

//  return player
// ---------------
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

// ---------------

// send move command to game
// ---------------
void Game::order(MOVE move)
{
    string saveMove = move;
    transform(move.begin(), move.end(), move.begin(), ::toupper);
    Cell* cell = gameBoard.search(cut_str(move).first);
    string nscore;
    bool check = false;
    if (moves.size() > 1)
    {
        nscore = *(moves.end() - 2);
        nscore = nscore.substr(2, 5);
        check = true;
        transform(nscore.begin(), nscore.end(), nscore.begin(), ::toupper);
    }
    if (Turn)
    {
        if (cell->getPiece() != nullptr)
        {
            if (cell->getPiece()->get_color() == player1->getcolor())
            {
                if (check)
                {
                    if (cut_str(nscore).second == cut_str(move).first && cut_str(nscore).first == cut_str(move).second)
                    {
                        player1->addScore(0, 2);
                    }
                }
                saveMove = string("P1") + saveMove; // player1 moved piece
                cell = gameBoard.search(cut_str(move).second);
                if (cell->getState())
                {
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
                        }
                        catch (const kishexcept &er)
                        {
                            gameBoard.undo(move, e.attack);
                            if (!player1->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
                            throw invalid_argument("you have kish can't this move!");
                        }
                        ID q = e.id;
                        attackpiece = e.attack;
                        e.attack = nullptr;
                        saveMove += "1";
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
                        catch (const kishexcept &er)
                        {
                            gameBoard.undo(move, nullptr);
                            if (!player1->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
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
                        if (!player1->iskish())
                        {
                            throw invalid_argument("this piece is pinned!");
                        }
                        throw invalid_argument("you have kish can't this move!");
                    }

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
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, attackpiece);
                            if (!player1->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
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
                        if (!player1->iskish())
                        {
                            throw invalid_argument("this piece is pinned!");
                        }
                        throw invalid_argument("you have kish can't this attack!");
                    }
                }
                moves.push_back(saveMove);
                Turn = false;
                return;

            }
            throw invalid_argument("!نوبت شما نیست");
        }
        throw invalid_argument("!مهره ای وجود ندارد");
    }
    else
    {
        if (cell->getPiece() != nullptr)
        {
            if (cell->getPiece()->get_color() == player2->getcolor())
            {
                if (check)
                {
                    if (cut_str(nscore).second == cut_str(move).first && cut_str(nscore).first == cut_str(move).second)
                    {
                        player1->addScore(0, 2);
                    }
                }
                saveMove = string("P2") + saveMove; // player1 moved piece
                cell = gameBoard.search(cut_str(move).second);
                if (cell->getState())
                {
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
                        }
                        catch (const kishexcept &r)
                        {
                            gameBoard.undo(move, e.attack);
                            if (!player2->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
                            throw invalid_argument("you have kish can't this move!");
                        }
                        ID q = e.id;
                        attackpiece = e.attack;
                        e.attack = nullptr;
                        saveMove += "1";
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
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, nullptr);
                            if (!player2->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
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
                    }
                    catch (const kishexcept &e)
                    {
                        gameBoard.undo(move, nullptr);
                        if (!player2->iskish())
                        {
                            throw invalid_argument("this piece is pinned!");
                        }
                        throw invalid_argument("you have kish can't this move!");
                    }
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
                        }
                        catch (const kishexcept &e)
                        {
                            gameBoard.undo(move, attackpiece);
                            if (!player2->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
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
                        if (!player2->iskish())
                        {
                            throw invalid_argument("this piece is pinned!");
                        }
                        throw invalid_argument("you have kish can't this move!");
                    }
                }
                moves.push_back(saveMove);
                Turn = true;
                return;

            }
            throw invalid_argument("!نوبت شما نیست");
        }
        throw invalid_argument("!مهره ای وجود ندارد");
    }
}

void Game::startgame()
{
    gameBoard.startboard();
}

// ---------------

// undo move
// ---------------

QString Game::undo(bool isreview)
{
    string move = moves.back();
    string tempscore;
    ChessMan * tempattack;
    bool undoprom = false;
    // find last move of player
    // this code is for exist two move option in program
    string temp = move.substr(2, 6);
    Cell *cellt;
    string undoenpassant;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    if (move.at(1) == '2')
    {
        if (temp.at(0) == 'P')
        {
            cellt = gameBoard.search(temp.substr(3, 2));
            if (cellt->getPiece()->get_type() != PAWN)
            {
                delete cellt->getPiece();
                cellt->setPiece(player2->getporomotion());
                undoprom = true;
            }
            
        }
        
        tempattack = player2->get_last_attack();
        try
        {
            gameBoard.undo(temp, tempattack);
        }
        catch(string & e)
        {
            *(temp.rbegin()) = '0';
            undoenpassant = e;
        }
        catch(castlingundo &e)
        {
            player2->addScore(0, 5);
            tempscore.append(move.begin() + 8, move.end());
            player2->addScore(1, -stoi(tempscore));
            Turn = false;
            moves.pop_back();
            if (!isreview)
            {
                file.removelastline();
            }
            throw e;
        }
        player2->addScore(0, 5);
        tempscore.append(move.begin() + 8, move.end());
        player2->addScore(1, -stoi(tempscore));
        Turn = false;
        moves.pop_back();
        if (temp.at(5) == '1')
        {
            temp.pop_back();
            undoattack e(temp, player2->getcolor());
            if (!isreview)
            {
                file.removelastline();
            }
            if (undoprom)
            {
                temp = move.substr(2, 5);
                string makeResult = temp[0] + temp.substr(3, 4) + temp.substr(1, 2);
                QString result = QString::fromStdString(makeResult);
                promotionundo er(result);
                er.attackUndo = true;
                er.e = e.color;
                Turn = false;
                throw er;
            }
            throw e;
        }
    }
    else if (move.at(1) == '1')
    {
        if (temp.at(0) == 'P')
        {
            cellt = gameBoard.search(temp.substr(3, 2));
            if (cellt->getPiece()->get_type() != PAWN)
            {
                delete cellt->getPiece();
                cellt->setPiece(player1->getporomotion());
                undoprom = true;
            }
            
        }
        tempattack = player1->get_last_attack();
        try
        {
            gameBoard.undo(temp, tempattack);
        }
        catch(string & e)
        {
            *(temp.rbegin()) = '0';
            undoenpassant = e;
        }
        catch(castlingundo &e)
        {
            player1->addScore(0, 5);
            tempscore.append(move.begin() + 8, move.end());
            player1->addScore(1, -stoi(tempscore));
            Turn = true;
            moves.pop_back();
            if (!isreview)
            {
                file.removelastline();
            }
            throw e;
        }
        player1->addScore(0, 5);
        tempscore.append(move.begin() + 8, move.end());
        player1->addScore(1, -stoi(tempscore));
        Turn = true;
        moves.pop_back();
        if (temp.at(5) == '1')
        {
            temp.pop_back();
            undoattack e(temp, player1->getcolor());
            if (!isreview)
            {
                file.removelastline();
            }
            if (undoprom)
            {
                temp = move.substr(2, 5);
                string makeResult = temp[0] + temp.substr(3, 4) + temp.substr(1, 2);
                QString result = QString::fromStdString(makeResult);
                promotionundo er(result);
                er.attackUndo = true;
                er.e = e.color;
                Turn = true;
                throw er;
            }
            throw e;
        }
    }
    //temp = move.substr(2, 5);
    temp.pop_back();
    string makeResult = temp[0] + temp.substr(3, 4) + temp.substr(1, 2);
    makeResult += undoenpassant;
    transform(makeResult.begin(), makeResult.end(), makeResult.begin(), ::tolower);
    QString result = QString::fromStdString(makeResult);
    if (!isreview)
    {
        file.removelastline();
    }
    if (undoprom)
    {
        promotionundo e(result);
        throw e;
    }
    qDebug() << result;
    return result;
}
// ---------------

// get moves command
// ---------------
std::vector<MOVE> Game::movesUndo()
{
    return moves;
}
// ---------------

// undate score for player
// ---------------
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
            attackpiece = nullptr;
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
                Special_mode = "-end";
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
            attackpiece = nullptr;
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
                Special_mode = "-end";
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
// ---------------

// get pscore of player
// ---------------
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
// ---------------

// restart game
// ---------------
void Game::restart()
{
    player1->restartScore();
    player2->restartScore();
}
// ---------------

// for pawn promotion
// ---------------
void Game::promotion(ID pawncell, piece typepiece)
{
    ChessMan *temppiece;
    Cell *temp = gameBoard.search(pawncell);
    switch (typepiece)
    {
    case QUEEN:
        temppiece = new queen(temp->getPiece()->get_color());
        Special_mode += "-1";
        break;
    case ROOK:
        temppiece = new rook(temp->getPiece()->get_color());
        Special_mode += "-2";
        break;
    case BISHOP:
        temppiece = new bishop(temp->getPiece()->get_color());
        Special_mode += "-3";
        break;
    case KNIGHT:
        temppiece = new knight(temp->getPiece()->get_color());
        Special_mode += "-4";
        break;
    case PAWN:
        temppiece = new pawn(temp->getPiece()->get_color());
        Special_mode += "-5";
        break;
    default:
        throw invalid_argument("piece type invalid");
        break;
    }
    ChessMan *chess = temp->getPiece();
    if (moves.back().at(1) == '1')
    {
        player1->addporomotion(chess);
    }
    else if (moves.back().at(1) == '2')
    {
        player2->addporomotion(chess);
    }
    temp->setPiece(temppiece);
}
// ---------------

// two move option for player's with -30 score
// -------------------
void Game::twomove()
{
    static size_t counter = 0; // if two move be moved, program return to normal run
    bool turnTemp;
    if(counter == 0)
    {
        turnTemp = !Turn; // save turn of player
        if(turnTemp)
        {
           player1->addScore(1, -30);
        } else {
            player2->addScore(1, -30);
        }
    }
    if(counter >= 2)
    {
        counter = 0;
        return;
    }
    counter++;
    Turn = turnTemp;
}
// -------------------

// this function get turn for ui
// ---------------
bool Game::getTurn()
{
    return Turn;
}
// ---------------

// for random move
// ---------------
std::string Game:: random_move()
{
    string move;
    if (Turn)
    {
        player1->addScore(0, -15);
        move = gameBoard.randommoves(player1->getcolor());
        this->order(move);

    }
    else
    {
        player2->addScore(0, -15);
        move = gameBoard.randommoves(player2->getcolor());
        this->order(move);
    }
    return move;

}
// ---------------

// save game in file
// ---------------
void Game::savegame()
{
    static bool first = true;
    if (first)
    {
        file.openFile(gamename + "-" + player1->get_name() + "-" + player2->get_name() + ".acd");
        first = false;
    }
    
    string save = moves.back();
    // save += "-p1PS-";
    // save += to_string(player1->getScore(1));
    // save += "-p1NS-";
    // save += to_string(player1->getScore(0));
    // save += "-p2PS-";
    // save += to_string(player2->getScore(1));
    // save += "-p2NS-";
    // save += to_string(player2->getScore(0));
    if (Special_mode.size() != 0)
    {
        if (Special_mode == "-end")
        {
            file.setendgame();
        }
        
        save += Special_mode;
    }
    file.WriteToFile(save);
}

// ---------------

// get game list for select game 
// ---------------
vector<QString> Game:: get_gamelist()
{
    auto temp = file.get_gamelist();
    string s = "sf";
    vector<QString> qs;
    stringstream f(s);
    string endgame;
    for (size_t i = 0; i < temp.size(); i++)
    {
        f = stringstream(temp.at((i)));
        getline(f, s, '-');
        while (getline(f, endgame, '-'))
        {
            if (endgame == "end")
            {
                s += "-end";
            }
        }
        qs.push_back(QString::fromStdString(s));
    }
    
    return qs;
}
// ---------------

// redo moves
// ---------------

QString Game:: redo()
{
    string move;
    move = file.ReadFromFile();
    string temp = move.substr(2,5);
    try
    {
        this->order(temp);
    }
    catch(pawnpromotion& e)
    {
        promotion(move.substr(5, 2), piece(stoi(move.substr(move.find('-') + 1))));
        throw temp + '-' + move.substr(move.find('-') + 1);
    }
    catch(enpassantexcept &e)
    {
        throw temp += "-e";
    }
    return QString::fromStdString(temp);
    
}
// ---------------

// select game
// ---------------

void Game::select_game(QString name)
{
    auto temp = file.get_gamelist();
    string s = "sf";
    vector<QString> qs;
    stringstream f(s);
    string path;
    for (size_t i = 0; i < temp.size(); i++)
    {
        f = stringstream(temp.at((i)));
        getline(f, s, '-');
        qs.push_back(QString::fromStdString(s));
    }
    for (size_t i = 0; i < qs.size(); i++)
    {
        if (name == qs.at(i))
        {
            path = temp.at(i);
            break;
        }
    }
    file.openFile(QString::fromStdString(path));
}
// ---------------

// check color of piece for hand nut
// ---------------
bool Game::checkColorOfPiece(string id)
{
    Cell* cell = gameBoard.search(id);
    if(Turn)
    {
        if(cell->getPiece()->get_color() == player1->getcolor())
        {
            return true; // this piece is for player
        }
    } else {
        if(cell->getPiece()->get_color() == player2->getcolor())
        {
            return true; // this piece is for player
        }
    }
    return false; // this piece is not for player
}
// ---------------

// add score's for players
// ---------------
void Game::addScore(size_t state, int score)
{
    // state = 0 --> negative score
    // state = 1 --> positive score

    if(Turn)
    {
        player1->addScore(state, score);
    }else {
        player2->addScore(state, score);
    }
}
// ---------------
