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

    void initializeGame();

signals:
    void gameOver();

private:
    void changeLifes(int num);

    /*!
     * \brief updateScore
     * \details should be caled after end of every level,
     * and after death.
     */
    void updateScore(double score);
    void saveScore();
private:
    int _activeLevel;
    int _numOfLifes;
    double _score;

    GameScene *_gameScene;
    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
