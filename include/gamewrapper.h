#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H

#include <QObject>
#include "include/gamewidget.h"
#include "include/game.h"

class GameWrapper
{
public:
    GameWrapper();
    GameWidget *getGameWidget() const;

private:
    Game *_game;
    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
