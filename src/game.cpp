#include "../include/game.h"
#include "../include/player.h"
#include "../include/enpassantexcept.h"
#include "../include/pawnpromotion.h"
#include "../include/undoattack.h"
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
    cerr << move << endl;
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
                            if (!player1->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
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
                            if (!player2->iskish())
                            {
                                throw invalid_argument("this piece is pinned!");
                            }
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
                        cout << "try\n";
                    }
                    catch (const kishexcept &e)
                    {
                        cout << "catch\n";
                        gameBoard.undo(move, nullptr);
                        if (!player2->iskish())
                        {
                            throw invalid_argument("this piece is pinned!");
                        }
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
    ChessMan * tempattack;
    // find last move of player
    // this code is for exist two move option in program
    string temp = move.substr(2, 6);
    Cell & cellt = gameBoard.search("A1");
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    if (move.at(1) == '2')
    {
        if (temp.at(0) == 'P')
        {
            cellt = gameBoard.search(temp.substr(3, 2));
            if (cellt.getPiece()->get_type() != PAWN)
            {
                cellt.setPiece(player2->getporomotion());
            }
            
        }
        
        tempattack = player2->get_last_attack();
        try
        {
            gameBoard.undo(temp, tempattack);
            temp.pop_back();
        }
        catch(string & e)
        {
            temp += e;
        }
        player2->addScore(0, 5);
        tempscore.append(move.begin() + 8, move.end());
        cout << "sc "  << tempscore << endl;
        player2->addScore(1, -stoi(tempscore));
        Turn = false;
        moves.pop_back();
        if (temp.at(5) == '1')
        {
            undoattack e(temp, player2->getcolor());
            cout << temp <<endl;
            throw e;
        }
    }
    else if (move.at(1) == '1')
    {
        if (temp.at(0) == 'P')
        {
            cellt = gameBoard.search(temp.substr(3, 2));
            if (cellt.getPiece()->get_type() != PAWN)
            {
                cellt.setPiece(player1->getporomotion());
            }
            
        }
        tempattack = player1->get_last_attack();
        try
        {
            gameBoard.undo(temp, tempattack);
            temp.pop_back();
        }
        catch(string & e)
        {
            temp += e;
        }
        player1->addScore(0, 5);
        tempscore.append(move.begin() + 8, move.end());
        cout << "sc " << tempscore << endl;
        player1->addScore(1, -stoi(tempscore));
        Turn = true;
        moves.pop_back();
        if (temp.at(5) == '1')
        {
            undoattack e(temp, player1->getcolor());
            cout << temp <<endl;
            throw e;
        }
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
            cout << "movescmd:: " << endl;
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
            cout << "movescmd:: " << endl;
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
            cout << "movescmd:: " << moves.back() << endl;
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
            cout << "movescmd:: " << moves.back() << endl;
            throw e;
        }
        if (player2->iskish())
        {
            player2->setkish(false);
        }
    }
    file.openFile(gamename + player1->get_name() + player2->get_name() + ".acd");
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
        cout << "PROMOTION: " << pawncell << endl;
        temppiece = new queen(temp->getPiece()->get_color());
        break;
    case ROOK:
        cout << "PROMOTION: " << pawncell << endl;
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

std::string Game:: random_move()
{
    cout << "random  \n";
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
    cout << "move :: " << move << endl;
    return move;

}

void Game::savegame()
{
    string save = moves.back();
    save += " p1 PS";
    save += to_string(player1->getScore(1));
    save += " NS";
    save += to_string(player1->getScore(0));
    save += " p2 PS";
    save += to_string(player2->getScore(1));
    save += " NS";
    save += to_string(player2->getScore(0));
    cout << save <<endl;
    file.WriteToFile(save);
}
