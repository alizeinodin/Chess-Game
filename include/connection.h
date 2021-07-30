#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QString>
#include "include/game.h"
#include <QChar>
#include <stdexcept>

class connection : public QObject
{
    Q_OBJECT

    // player1 socre smart variable
    Q_PROPERTY(int player1PScore READ player1PScore WRITE setPlayer1PScore NOTIFY player1PScoreChanged)
    Q_PROPERTY(int player1NScore READ player1NScore WRITE setPlayer1NScore NOTIFY player1NScoreChanged)

    // player2 score samrt variable
    Q_PROPERTY(int player2PScore READ player2PScore WRITE setPlayer2PScore NOTIFY player2PScoreChanged)
    Q_PROPERTY(int player2NScore READ player2NScore WRITE setPlayer2NScore NOTIFY player2NScoreChanged)

    // name's of player's
    Q_PROPERTY(QString player1Name READ player1Name WRITE setPlayer1Name NOTIFY player1NameChanged)
    Q_PROPERTY(QString player2Name READ player2Name WRITE setPlayer2Name NOTIFY player2NameChanged)
public:
    explicit connection(QObject *parent = nullptr);

signals:
    // score's of players
    void player1PScoreChanged();
    void player1NScoreChanged();
    void player2PScoreChanged();
    void player2NScoreChanged();

    // name's of player's
    void player1NameChanged();
    void player2NameChanged();

    // move piece in chessBoard signals
    void successMove();

public slots:

    // scores smart update

    // player1
    // positive
    int player1PScore();
    void setPlayer1PScore(int);
    // negative
    int player1NScore();
    void setPlayer1NScore(int);

    // player2
    // postive
    int player2PScore();
    void setPlayer2PScore(int);
    // negative
    int player2NScore();
    void setPlayer2NScore(int);

    // end

    // player's name's
    // player1
    QString player1Name();
    void setPlayer1Name(QString);

    // player2
    QString player2Name();
    void setPlayer2Name(QString);

    // set order and run program
    void setOrder(QString);




private:

    Game * game = nullptr;

    // player's score
    int P1ScoreP = 0; // positive score of player1
    int P1ScoreN = 0; // negative score of player1
    int P2ScoreP = 0; // positive score of player2
    int P2ScoreN = 0; // negative score of player2

    // player's name
    QString P1Name;
    QString P2Name;

};

#endif // CONNECTION_H
