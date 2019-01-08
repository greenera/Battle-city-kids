#include "include/gamewrapper.h"

GameWrapper::GameWrapper(QWidget *parrent)
    : QObject(parrent)
{
    //construct Game and GameWidget
    _game = new Game();
    _gameWidget = new GameWidget(parrent, _game);

    initializeGame();
}

GameWidget *GameWrapper::getGameWidget() const
{
    return _gameWidget;
}

void GameWrapper::initializeGame()
{
    //TODO: dodati brisanje stare scene
    _game->clear();

    //pravljenje scene
    //TODO: preurediti
    _game->initializeGame();
    _gameWidget->printMap(_game->matrixOfLevel);

    _activeLevel = 1;
    _numOfLifes = 3;
    //_score = 0;
}

void GameWrapper::changeLifes(int num)
{
    _numOfLifes += num;
    if(_numOfLifes < 0)
    {
        _game->clear();
        emit this->gameOver();
    }
}
