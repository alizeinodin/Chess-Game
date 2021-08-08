#include "../include/connection.h"
#include "../include/kishexcept.h"
#include <iostream>
#include <QDebug>
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
    if(!order[0].isUpper())
    {
        emit loseMove();
    }

    qDebug() << order;
    try {
        game->order(order.toStdString());
        game->update_score();
        updateScore();
        emit successMove();
    } catch (invalid_argument & error) {
        messageStr = error.what();
        emit loseMove();
    }
     catch (kishexcept & error){
         messageStr = error.what();
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
             emit mat();
        } catch (Equality) {
            winnerName = player1Name() + QString(" و ") + player2Name();
            winnerScore = game->getPlayer("White").getScore(1);
            winnertxt = QString("مساوی شدید");
        }
    }
    order.clear();
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
    QString order = game->undo(), firstCell = order.mid(1, 2), secondCell = order.mid(3, 2);
    orgIdVal = firstCell;
    destIdVal = secondCell;
    updateScore();

    if(counter > 0)
    {
        counter++;
    }

    emit undoMove();
}
// ------------

// restart game slot
// ------------
void connection::restart()
{
    if(counter == 0)
    {
        counter = 1;
    }
    if (counter <= game->movesUndo().size()) {
        undo();
    }
    if(counter > game->movesUndo().size())
    {
        counter = 1;
        game->restart();
        updateScore();
    }
}
// ------------

// exit game
// ------------
void connection::exitGame()
{
    delete game;
    restart();
    emit exit();
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
}
// ------------

// counter smart var
// ------------
void connection::setCounterRestart(unsigned long cnt)
{
    counter = cnt;
}

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
