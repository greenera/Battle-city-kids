#include "include/gamewrapper.h"

GameWrapper::GameWrapper()
{
    _game = new Game();
    _gameWidget = new GameWidget();
    _game->initializeGame();
    _gameWidget->printMap(_game->matrixOfLevel);
}

GameWidget *GameWrapper::getGameWidget() const
{
    return _gameWidget;
}
