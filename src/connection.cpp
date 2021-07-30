#include "include/connection.h"
#include <QDebug>
using namespace std;

connection::connection(QObject *parent) : QObject(parent)
{
//    connect(this, &connection::setOrder, this, &connection::show);
    game = &Game::getInstance();
}
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
        throw invalid_argument("دستور نامعتبر است");
    }
    qDebug() << order;
    emit successMove();
}
// ------------


