#include "include/gamewrapper.h"

GameWrapper::GameWrapper(QWidget *parrent)
    :QObject(parrent)
{
    _gameWidget = new GameWidget(parrent);

    QObject::connect(_gameWidget, &GameWidget::endOfLevel,
                     this, &GameWrapper::onEndOfLevel);

    QObject::connect(_gameWidget->getGameScene(), &Game::killed,
                     this, &GameWrapper::changeLifes);
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
    _gameWidget->setLifeInformation(_numOfLifes);
}

void GameWrapper::changeLifes()
{
    if (--_numOfLifes < 0)
    {
        updateScore(0); //!< only add for level reached
        saveScore();
        _gameWidget->abort();
        emit this->gameOver();
    }
    _gameWidget->setLifeInformation(_numOfLifes);
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
