#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H

#include <QObject>
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

private:
    int _activeLevel;
    int _numOfLifes;

    GameScene *_gameScene;
    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
