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
        emit successMove();
        game->update_score();
        updateScore();
    } catch (invalid_argument & errorOrder) {
        std::cerr << errorOrder.what() << std::endl;
        emit loseMove();
    }
     catch (kishexcept & error){
         std::cerr << error.what() << std::endl;
         emit loseMove();
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
    emit undoMove();
}
// ------------

// restart game slot
// ------------
void connection::restart()
{
    for (size_t i = 0; i < game->movesUndo().size(); i++) {
        undo();
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
