#include "include/gameproxy.h"

GameProxy::GameProxy(GameWidget* gameWidget)
{
    _gameWidget = gameWidget;

    QObject::connect(_gameWidget, &GameWidget::endOfLevel,
                     this, &GameProxy::onEndOfLevel);

    QObject::connect(_gameWidget->getGameScene(), &GameScene::killed,
                     this, &GameProxy::changeLifes);

    QObject::connect(_gameWidget->getGameScene(), &GameScene::exitRequested,
                     this, &GameProxy::exitToMainMenu);
}

void GameProxy::initializeGame(int numOfPlayers)
{
    //javi gameWidgetu da se inicijalizuje
    _gameWidget->initializeLevel(1, numOfPlayers);

    //inicijalizuj svoje vrednosti
    _activeLevel = 1;
    _numOfLives = 3;
    _playersNum = numOfPlayers;
    _score = 100;
    _gameWidget->setLifeInformation(_numOfLives);
}

void GameProxy::changeLifes()
{
    if (--_numOfLives < 0)
    {
        updateScore(0); //!< only add for level reached
        saveScore();
        _gameWidget->abort();
        emit gameOver();
    }
    _gameWidget->setLifeInformation(_numOfLives);
}

void GameProxy::exitToMainMenu()
{
    updateScore(0);
    saveScore();
    _gameWidget->abort();
    emit gameOver();
}

void GameProxy::updateScore(double bonus)
{
    _score += bonus + _activeLevel + _numOfLives;
}

void GameProxy::saveScore()
{
    QFile file("resources/score.txt");
    file.open(QIODevice::ReadOnly);
    QString bestScore = file.readLine();
    if (bestScore.toDouble() < _score) {
        file.close();
        file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
        QTextStream out(&file);
        out << _score << endl;
    }
    file.close();
}

void GameProxy::onEndOfLevel(double bonus)
{
    updateScore(bonus);

    //show short sum

    if (++_activeLevel <= NUM_OF_LEVELS)
        _gameWidget->initializeLevel(_activeLevel, _playersNum);
}
