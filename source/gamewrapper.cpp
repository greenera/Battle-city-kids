#include "include/gamewrapper.h"

GameWrapper::GameWrapper(QWidget *parrent)
    :QObject(parrent)
{
    _gameWidget = new GameWidget(parrent);
    _gameScene = _gameWidget->getGameScene();

    QObject::connect(_gameScene, &Game::endOfLevel,
                     this, &GameWrapper::updateScore);
}

GameWidget *GameWrapper::getGameWidget() const
{
    return _gameWidget;
}

void GameWrapper::initializeGame()
{
    //javi gameWidgetu da se inicijalizuje
    _gameWidget->initializeGame();

    //inicijalizuj svoje vrednosti
    _activeLevel = 1;
    _numOfLifes = 3;
    _score = 100;
}

void GameWrapper::changeLifes(int num)
{
    _numOfLifes += num;
    if(_numOfLifes < 0)
    {
        _gameScene->clear();
        //updateScore(); make sure that score is signaled for update from gameScene
        saveScore();
        emit this->gameOver();
    }
}

//TODO: namestiti da se bonus racuna kao suma proizvoda
//jacine tenka i broja ubijenih te vrste/vremenom
void GameWrapper::updateScore(double bonus)
{
    _score += bonus + _activeLevel + _numOfLifes;
}

void GameWrapper::saveScore()
{
    //TODO: implementirati
}
