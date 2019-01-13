#include "include/gamewrapper.h"

GameWrapper::GameWrapper(QWidget *parrent)
    :QObject(parrent)
{
    _gameWidget = new GameWidget(parrent);
    _gameScene = _gameWidget->getGameScene();

    QObject::connect(_gameWidget, &GameWidget::endOfLevel,
                     this, &GameWrapper::onEndOfLevel);
}

GameWidget *GameWrapper::getGameWidget() const
{
    return _gameWidget;
}

void GameWrapper::initializeGame()
{
    //javi gameWidgetu da se inicijalizuje
    _gameWidget->initializeLevel(1);

    //inicijalizuj svoje vrednosti
    _activeLevel = 1;
    _numOfLifes = 3;
    _score = 100;
}

void GameWrapper::changeLifes(int num)
{
    _numOfLifes += num;
    if (_numOfLifes < 0)
    {
        _gameScene->clear();
        updateScore(0); //!< only add for level reached
        saveScore();
        _gameWidget->abort();
        emit this->gameOver();
    }
}

void GameWrapper::updateScore(double bonus)
{
    _score += bonus + _activeLevel + _numOfLifes;
}

void GameWrapper::saveScore()
{
    //TODO: implementirati
}

void GameWrapper::onEndOfLevel(double bonus)
{
    updateScore(bonus);

    //show short sum

    if (++_activeLevel <= NUM_OF_LEVELS)
        _gameWidget->initializeLevel(_activeLevel);
}
