#include "../include/connection.h"
#include "../include/kishexcept.h"
#include "../include/undoattack.h"
#include "../include/enpassantexcept.h"
#include "../include/pawnpromotion.h"
#include "../include/promotionundo.h"
#include "../include/castling.h"
#include <iostream>
#include <QDebug>
#include <QApplication>
#include <sstream>
#include <QProcess>

using namespace std;

connection::connection(QObject *parent) : QObject(parent)
{
}
connection::~connection()
{
    if(game != nullptr)
        delete game;
}

// game name variable
// ------------
void connection::setGName(QString name)
{
    gameName = name;
    emit GNameChanged();
}

QString connection::GName()
{
    return gameName;
}
// ------------

// score update player1 postive
// ------------
int connection::player1PScore()
{
    return P1ScoreP;
}

void connection::setPlayer1PScore(int value)
{
    P1ScoreP = value;
    emit player1PScoreChanged();
}

// ------------

// score update player1 negative
// ------------
int connection::player1NScore()
{
    return P1ScoreN;
}

void connection::setPlayer1NScore(int value)
{
    P1ScoreN = value;
    emit player1NScoreChanged();
}
// ------------

// score update player2 postive
// ------------
int connection::player2PScore()
{
    return P2ScoreP;
}

void connection::setPlayer2PScore(int value)
{
    P2ScoreP = value;
    emit player2PScoreChanged();
}

// ------------

// score update player2 negative
// ------------
int connection::player2NScore()
{
    return P2ScoreN;
}

void connection::setPlayer2NScore(int value)
{
    P2ScoreN = value;
    emit player2NScoreChanged();
}
// ------------

// name of player 1
// ------------
QString connection::player1Name()
{
    return P1Name;
}

void connection::setPlayer1Name(QString value)
{
    P1Name = value;
    emit player1NameChanged();
}
// ------------

// name of player 2
// ------------
QString connection::player2Name()
{
    return P2Name;
}

void connection::setPlayer2Name(QString value)
{
    P2Name = value;
    emit player2NameChanged();
}

void connection::setOrder(QString order)
{
    // check exist piece in orginal cell
    // ----------
    if(!order[0].isUpper())
    {
        emit loseMove();
    }
    // ----------

    // check hand to the nut
    // ----------
    if(order[3].isUpper())
    {
        std::string destid = order.mid(4, 2).toUpper().toStdString();
        if(game->checkColorOfPiece(destid)) // hand to the nut is true
        {
            orgIdVal = QString::fromStdString(destid).toLower();
            if(!handToTheNut)
            {
                game->addScore(0 ,1);
                updateScore();
                handToTheNut = true;
            }
            emit handNut();
            return;
        }else {
            order = order.mid(0, 3) + order.mid(4, 2); // this move is attack
        }
    }
    // ----------
    try {

        // random move for 15 negative socore
        // ----------
//        if (game->getTurn())
//        {
//            if (game->getPlayer(std::string("White")).getScore(0) >= 15)
//            {
//                order = QString::fromStdString(game->random_move());
//                QString firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
//                orgIdVal = secondCell;
//                destIdVal = firstCell;
//                setCheckRandom(true);
//                return;
//            }
//            else {
//                if (game->getPlayer(std::string("Black")).getScore(0) == 15)
//                {
//                    order = QString::fromStdString(game->random_move());
//                    QString firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
//                    orgIdVal = secondCell;
//                    destIdVal = firstCell;
//                    setCheckRandom(true);
//                    return;
//                }
//            }
//        }
        // ----------

//        if(checkRandom())
//        {
//            order = order.toLower();
//            orgIdVal = order.mid(1, 2);
//            destIdVal = order.mid(3, 2);
//            tempIdVal = order;
//        }

        game->order(order.toStdString());
        if(twoMoveAccess)
        {
            twoMove();
            game->twomove();
        }
        game->update_score();
        game->savegame();
        updateScore();
        handToTheNut = false;
        order.clear();
        emit successMove();
    } catch (kishexcept & error){
        messageStr = error.what();
        if(twoMoveAccess)
        {
            twoMove();
            game->twomove();
        }
        //        game->update_score();
        updateScore();
        handToTheNut = false;
        order.clear();
        emit kish();
    }
    catch (matexcept & error){
        try {
            Player & winner = game->compareScore();
            if(winner.getcolor() == "White")
            {
                winnerName = player1Name();
            } else {
                winnerName = player2Name();
            }
            winnerScore = winner.getScore(1);
            winnertxt = QString("برنده شدید");
            if(twoMoveAccess)
            {
                twoMove();
                game->twomove();
            }
            updateScore();
            handToTheNut = false;
            order.clear();
            emit mat();
        } catch (Equality & error) {
            winnerName = player1Name() + QString(" و ") + player2Name();
            winnerScore = game->getPlayer("White").getScore(1);
            if(twoMoveAccess)
            {
                twoMove();
                game->twomove();
            }
            //            game->update_score();
            updateScore();
            handToTheNut = false;
            winnertxt = QString("مساوی شدید");
            order.clear();
        }
    } catch (enpassantexcept & piece)
    {
        enpassentPiece = QString::fromStdString(piece.id);
        if(twoMoveAccess)
        {
            twoMove();
            game->twomove();
        }
        game->update_score();
        updateScore();
        handToTheNut = false;
        order.clear();
        emit enPassent();
    } catch(pawnpromotion & mypromotion)
    {
        game->update_score();
        updateScore();
        handToTheNut = false;
        order.clear();

        emit promotion();
    }
    catch (exception & error) {
        messageStr = error.what();
        if(twoMoveAccess)
        {
            twoMove();
            game->twomove();
        }
        updateScore();
        handToTheNut = false;
        order.clear();
        emit loseMove();
    }
}

// ------------

// start game
// ------------
void connection::startGame(QString name)
{
    setGName(name);
    this->game = new Game(gameName);
    game->setPlayer(Game::Color::WHITE, P1Name);
    game->setPlayer(Game::Color::BLACK, P2Name);
    game->startgame();
}
// ------------

// undo btn slot
// ------------
void connection::undo()
{
    try{
        QString order = game->undo(false), firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
        orgIdVal = firstCell;
        destIdVal = secondCell;
        if(order.length() > 5) // undo of en passent
        {
            undoPieceColor = game->getTurn() == true ? QString("White") : QString("Black");
            QString third = order.mid(5, 2);
            tempIdVal = third;
            updateScore();
            emit undoEnpassent();
        }
        updateScore();
        emit undoMove();
    } catch(undoattack & myPiece)
    {
        QString order = QString::fromStdString(myPiece.id), firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
        orgIdVal = secondCell.toLower();
        destIdVal = firstCell.toLower();
        undoPieceColor = QString::fromStdString(myPiece.color);
        updateScore();
        emit undoAttack();
    } catch (promotionundo & myOrder)
    {
        QString order = myOrder.id, firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
        setPromotion(5, secondCell.toUpper());
        orgIdVal = firstCell;
        destIdVal = secondCell;
        if(myOrder.attackUndo)
        {
            undoPieceColor = QString::fromStdString(myOrder.e);
            emit undoPromotionAttack();
        }
        updateScore();
        emit undoPromotion();
    } catch(castlingundo & myOrder)
    {
        QString order = QString::fromStdString(myOrder.rookid).toLower(), firstCell = order.mid(0, 2), secondCell = order.mid(2, 2);
        orgIdVal = firstCell;
        destIdVal = secondCell;
        undoCastKing = QString::fromStdString(myOrder.undomove).toLower();
        updateScore();
        emit undoCastleing();
    } catch (exception & error) {
        messageStr = error.what();
        if(twoMoveAccess)
        {
            twoMove();
            game->twomove();
        }
        updateScore();
        handToTheNut = false;
        emit loseMove();
    }
}
// ------------

// restart game slot
// ------------
void connection::restart()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
// ------------

// exit game
// ------------
void connection::exitGame()
{
    if(game != nullptr)
    {
        delete game;
    }
    qApp->quit();
}
// ------------

// QML id's
// ------------
QString connection::orgId()
{
    return orgIdVal;
}

QString connection::destId()
{
    return destIdVal;
}

QString connection::tempId()
{
    return tempIdVal;
}

// ------------

// update score
// ------------
void connection::updateScore()
{
    // player 1 update score
    setPlayer1NScore(game->getPlayer(std::string("White")).getScore(0));
    setPlayer1PScore(game->getPlayer(std::string("White")).getScore(1));

    // player2 update score
    setPlayer2NScore(game->getPlayer(std::string("Black")).getScore(0));
    setPlayer2PScore(game->getPlayer(std::string("Black")).getScore(1));

    setTurnGame(game->getTurn());

}
// ------------

// counter Wvar
// ------------
unsigned long connection::counterRestart()
{
    return counter;
}
// ------------

// get error.what of exceptions to ui
// ------------
QString connection::getMessage()
{
    QString result = QString::fromStdString(messageStr);
    return result;
}
// ------------

// winner data slots
// ------------
QString connection::getWinnerName()
{
    QString result = winnerName + QString(" عزیز");
    return result;
}

QString connection::getWinnerScore()
{
    QString result = QString::fromStdString(to_string(winnerScore));
    return result;
}

QString connection::getWinnerText()
{
    return winnertxt;
}
// ------------

// turn smart variable
// ------------
void connection::setTurnGame(bool turn)
{
    this->turn = turn;
}
bool connection::turnGame()
{
    return turn;
}
// ------------

// get undo piece color
// ------------
QString connection::getUndoAttackColor()
{
    return undoPieceColor;
}
// ------------

// get enpassent piece
// ------------
QString connection::getEnPassentPiece()
{
    return enpassentPiece.toLower();
}
// ------------

// two move
// ------------
void connection::twoMove()
{
    if(game->getTurn())
    {
        if(player1PScore() < 30)
        {
            messageStr = string("امتیاز شما کمتر از ۳۰ است");
            twoMoveAccess = false;
            emit loseMove();
            return;
        }
    } else {
        if(player2PScore() < 30)
        {
            messageStr = string("امتیاز شما کمتر از ۳۰ است");
            twoMoveAccess = false;
            emit loseMove();
            return;
        }
    }
    static size_t counter = 0;
    if(counter >= 2)
    {
        counter = 0;
        twoMoveAccess = false;
        return;
    }
    counter++;
    twoMoveAccess = true; // access for two move
}
// ------------

// set promotion slot
// ------------
void connection::setPromotion(int state, QString id)
{
    piece piece;
    id = id.toUpper();

    switch (state) {
    case 1:
        piece = ROOK;
        break;
    case 2:
        piece = BISHOP;
        break;
    case 3:
        piece = QUEEN;
        break;
    case 4:
        piece = KNIGHT;
        break;
    case 5:
        piece = PAWN;
        break;
    }
    game->promotion(id.toStdString(), piece);
}
// ------------

// get index of game list for review
// ------------
int connection::getindexgame()
{
    auto index = game->get_gamelist();
    return index.size();
}
// ------------

// undo castleing, undo order for king
// ------------
void connection::undoCastleingKing()
{
    QString order = undoCastKing, firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
    orgIdVal = secondCell;
    destIdVal = firstCell;
    updateScore();
    emit undoMove();
}
// ------------

// checking random. if random move is start, it is true
// ------------
bool connection::checkRandom()
{
    return checkrandom;
}

void connection::setCheckRandom(bool check)
{
    checkrandom = check;
}


// ------------

// cancel game
// ------------
void connection::cancel()
{
    updateScore();
    if(game->getTurn())
    {
        winnerName = player2Name();
        winnerScore = game->getPlayer("Black").getScore(1);
    } else {
        winnerName = player1Name();
        winnerScore = game->getPlayer("White").getScore(1);
    }
    winnertxt = QString("برنده شدید");
    if(twoMoveAccess)
    {
        twoMove();
        game->twomove();
    }
    handToTheNut = false;
    emit mat();
}
// ------------

// get random string
// ------------
QString connection::getRandom()
{
    QString order;
    if (game->getTurn())
    {
        if (game->getPlayer(std::string("White")).getScore(0) >= 15)
        {
            order = QString::fromStdString(game->random_move());
            //            setCheckRandom(true);
        }
    } else {
        if (game->getPlayer(std::string("Black")).getScore(0) >= 15)
        {
            order = QString::fromStdString(game->random_move());
            //            setCheckRandom(true);
        }
    }
    QString firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
    orgIdVal = secondCell.toLower();
    destIdVal = firstCell.toLower();
    order = order[0]+order.mid(1, 4).toLower();
    updateScore();
    return order;
}
// ------------

// get game name
// ------------
//QString connection::getgamename(int index)
//{
//    auto name = game->get_gamelist();
//    string temp = name.at(index).toStdString();
//    stringstream tok(temp);
//    string endstr;
//    getline(tok, endstr, '-');
//    getline(tok, endstr, '-');
//    if (endstr == "end") {
//        emit end();
//    }
//    return name.at(index);
//}
