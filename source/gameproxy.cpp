#include "include/gameproxy.h"

GameProxy::GameProxy(QWidget *parrent)
    : QObject(parrent)
{
    //construct Game and GameWidget
    _gameScene = new GameScene();
    _gameWidget = new GameWidget(parrent, _gameScene);

    initializeGame();
}

GameWidget *GameProxy::getGameWidget() const
{
    return _gameWidget;
}

void GameProxy::initializeGame()
{
    //TODO: dodati brisanje stare scene
    //_game->clear();

    //pravljenje scene
    //TODO: preurediti
    _gameScene->initializeGame();
    _gameScene->printMap(_gameScene->matrixOfLevel);

    _activeLevel = 1;
    _numOfLifes = 3;
    //_score = 0;
}

void GameProxy::changeLifes(int num)
{
    _numOfLifes += num;
    if(_numOfLifes < 0)
    {
        _gameScene->clear();
        emit this->gameOver();
    }
}
