#include "include/gamewrapper.h"

GameWrapper::GameWrapper()
{
    _game = new Game();
    _gameWidget = new GameWidget();
}

GameWidget *GameWrapper::getGameWidget()
{
    return _gameWidget;
}
