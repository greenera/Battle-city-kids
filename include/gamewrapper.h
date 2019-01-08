#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H

#include <QObject>
#include "include/gamewidget.h"
#include "include/game.h"

class GameWrapper : public QObject
{
    Q_OBJECT

public:
    GameWrapper(QWidget *parent);
    GameWidget *getGameWidget() const;

    void initializeGame();

signals:
    void gameOver();

private:
    void changeLifes(int num);

private:
    int _activeLevel;
    int _numOfLifes;

    Game *_game;
    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
