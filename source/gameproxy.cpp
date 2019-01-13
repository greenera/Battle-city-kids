#include "include/gameproxy.h"

GameProxy::GameProxy(QWidget *parrent)
    :QObject(parrent)
{
    _gameWidget = new GameWidget(parrent);
    _gameScene = _gameWidget->getGameScene();

    QObject::connect(_gameScene, &GameScene::endOfLevel,
                     this, &GameProxy::updateScore);
}

GameWidget *GameProxy::getGameWidget() const
{
    return _gameWidget;
}

void GameProxy::initializeGame()
{
    //javi gameWidgetu da se inicijalizuje
    _gameWidget->initializeGame();

    //inicijalizuj svoje vrednosti
    _activeLevel = 1;
    _numOfLifes = 3;
    _score = 100;
}

void GameProxy::changeLifes(int num)
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
void GameProxy::updateScore(double bonus)
{
    _score += bonus + _activeLevel + _numOfLifes;
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
