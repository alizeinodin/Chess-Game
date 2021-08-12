#ifndef CONNECTION_H
#define CONNECTION_H

//#include <QObject>
#include <QString>
#include "include/game.h"
#include <stdexcept>
#include <QQuickView>
#include <QObject>
#include <QQuickItem>
#include <QQmlEngine>

class connection : public QObject
{
    Q_OBJECT

    // game name smart variable
    Q_PROPERTY(QString GName READ GName WRITE setGName NOTIFY GNameChanged)

    // player1 socre smart variable
    Q_PROPERTY(int player1PScore READ player1PScore WRITE setPlayer1PScore NOTIFY player1PScoreChanged)
    Q_PROPERTY(int player1NScore READ player1NScore WRITE setPlayer1NScore NOTIFY player1NScoreChanged)

    // player2 score samrt variable
    Q_PROPERTY(int player2PScore READ player2PScore WRITE setPlayer2PScore NOTIFY player2PScoreChanged)
    Q_PROPERTY(int player2NScore READ player2NScore WRITE setPlayer2NScore NOTIFY player2NScoreChanged)

    // name's of player's
    Q_PROPERTY(QString player1Name READ player1Name WRITE setPlayer1Name NOTIFY player1NameChanged)
    Q_PROPERTY(QString player2Name READ player2Name WRITE setPlayer2Name NOTIFY player2NameChanged)

    // trun of game
    Q_PROPERTY(bool turnGame READ turnGame WRITE setTurnGame NOTIFY turnGameChanged)

public:
    explicit connection(QObject *parent = nullptr);
    void updateScore();
    ~connection();

signals:
    // name of game
    void GNameChanged();

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
    void loseMove();

    QString showName();
    void undoMove();

    // exit game
    void exit();

    // signal object
    void counterRestartChanged();

    // kish signal
    void kish();

    // mat signal
    void mat();

    // castleing
    void castleing();

    // turn of game
    void turnGameChanged();

    // undo attack piece
    void undoAttack();

    // en passent
    void enPassent();

    // pawn promotion
    void promotion();


public slots:

    // game name

    void setGName(QString);
    QString GName();

    // end

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

    // set name of game and start game
    void startGame(QString);

    // undo btn slot
    void undo();

    // restart game
    void restart();

    // exit game
    void exitGame();

    //     id's in qml
    //     org
    QString orgId();
    // dest
    QString destId();

    // counter restart
    unsigned long counterRestart();

    // get message
    QString getMessage();

    // get winner data
    QString getWinnerName();
    QString getWinnerScore();
    QString getWinnerText();

    // turn of game
    bool turnGame();
    void setTurnGame(bool);

    // get undo attack piece
    QString getUndoAttackColor();

    // get En Passent piece
    QString getEnPassentPiece();

    // two move slot
    void twoMove();

    // promotion pawn slot
    void setPromotion(int, QString);

    // get index of game list for review
    int getindexgame();

    // get game name
    QString getgamename(int);

private:

    Game * game = nullptr;
    QString gameName;
    std::string messageStr;

    // turn of game
    bool turn;


    // player's score
    int P1ScoreP = 0; // positive score of player1
    int P1ScoreN = 0; // negative score of player1
    int P2ScoreP = 0; // positive score of player2
    int P2ScoreN = 0; // negative score of player2

    // player's name
    QString P1Name;
    QString P2Name;

    // org and dest id
    QString orgIdVal;
    QString destIdVal;

    // counter
    unsigned long counter = 0;

    // winner data
    QString winnerName;
    unsigned long int winnerScore;
    QString winnertxt;

    // undo attack recognize piece
    QString undoPieceColor;

    // enpassent piece
    QString enpassentPiece;

    // two move access
    bool twoMoveAccess = false;
};

#endif // CONNECTION_H
