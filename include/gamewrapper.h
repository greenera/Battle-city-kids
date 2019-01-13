#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H

#include <QObject>
#include "include/gamewidget.h"
#include "include/game.h"

class GameWrapper : public QObject
{
    Q_OBJECT

public:
    GameWrapper(QWidget *parrent);
    GameWidget *getGameWidget() const;

    void initializeGame();

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
    int _numOfLifes;
    double _score;

    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
