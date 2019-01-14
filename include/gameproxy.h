#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "include/gamewidget.h"
#include "include/gamescene.h"


class GameProxy : public QObject
{
    Q_OBJECT

public:
    GameProxy(QWidget *parent);
    GameWidget *getGameWidget() const;

    void initializeGame(int numOfPlayers);

signals:
    void gameOver();

private:
    void changeLifes();

    /*!
     * \brief updateScore
     * \details should be caled after end of every level,
     * and after death.
     */
    void updateScore(double score);
    void saveScore();

public slots:
    void onEndOfLevel(double bonus);

private:
    int _activeLevel;
    int _numOfLives;
    int _playersNum;
    double _score;

    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
