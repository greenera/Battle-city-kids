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

    Game *_gameScene;
    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
