#include "include/game.h"
#include <QFile>
/**
 * @brief Game::Game
 * @param parrent
 * \details Scena koja predstavlja igru. Tu se regulise igra u okviru nivoa.
 * Trebalo bi preimenovati je u levelScene, takodje prebaciti sve sto ima veze sa scenom ovde.
 */


Game::Game(QWidget* parrent)
    : QGraphicsScene(parrent),
    matrixOfLevel(26, QVector<int>(26))
{
    this->setSceneRect(0, 0, _sizeOfScene, _sizeOfScene);
    setBackgroundBrush(QColor(0, 0, 0));

    initializeGame();

    QTimer _updateTimer;
    _updateTimer.setInterval(500);
    _updateTimer.start();
    //QObject::connect(_updateTimer, &QTimer::timeout, this, &Game::update);
}


void Game::initializeGame()
{
    loadLevel(2);

    //createNpcs(); TODO Ivana: implementiraj
}

// Loads level from file
void Game::loadLevel(int levelNum)
{
    QString path = QStringLiteral(":/levels/%1.txt").arg(levelNum);
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    char c;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            file.read(&c,sizeof(char));
            if(c == '\n') {
                j--;
                continue;
            }
            matrixOfLevel[i][j] = c - '0'; // Read data into matrix
        }
    }
    file.close(); // Close the file
}


//TODO: srediti da ne moze da se krece ukoso
void Game::keyPressEvent(QKeyEvent *event)
{
    //consider 'w' 'a' 's' and 'd'
    if(event->key() == Qt::Key_W)
    {
        _players[0]->setUp(true);
    }
    else if (event->key() == Qt::Key_A)
    {
        _players[0]->setLeft(true);
    }
    else if (event->key() == Qt::Key_D)
    {
        _players[0]->setRight(true);
    }
    else if (event->key() == Qt::Key_S)
    {
        _players[0]->setDown(true);
    }

    //consider 'up' 'down' 'left' and 'right'
    if(_players[1] != nullptr)
    {
        if(event->key() == Qt::Key_Up)
        {
            _players[1]->setUp(true);
        }
        else if (event->key() == Qt::Key_Left)
        {
            _players[1]->setLeft(true);
        }
        else if (event->key() == Qt::Key_Right)
        {
            _players[1]->setRight(true);
        }
        else if (event->key() == Qt::Key_Down)
        {
            _players[1]->setDown(true);
        }
    }

    //TODO: add checking for pause and backToMenu
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    //consider 'w' 'a' 's' and 'd'
    if(event->key() == Qt::Key_W)
    {
        _players[0]->setUp(false);
    }
    else if (event->key() == Qt::Key_A)
    {
        _players[0]->setLeft(false);
    }
    else if (event->key() == Qt::Key_D)
    {
        _players[0]->setRight(false);
    }
    else if (event->key() == Qt::Key_S)
    {
        _players[0]->setDown(false);
    }

    //consider 'up' 'down' 'left' and 'right'
    if(_players[1] != nullptr)
    {
        if(event->key() == Qt::Key_Up)
        {
            _players[1]->setUp(false);
        }
        else if (event->key() == Qt::Key_Left)
        {
            _players[1]->setLeft(false);
        }
        else if (event->key() == Qt::Key_Right)
        {
            _players[1]->setRight(false);
        }
        else if (event->key() == Qt::Key_Down)
        {
            _players[1]->setDown(false);
        }
    }
}
