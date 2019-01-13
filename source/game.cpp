#include "include/game.h"
#include <QFile>

#include <QDebug>

/**
 * @brief Game::Game
 * @param parrent
 * \details Scena koja predstavlja igru. Tu se regulise igra u okviru nivoa.
 * Trebalo bi preimenovati je u levelScene, takodje prebaciti sve sto ima veze sa scenom ovde.
 */
Game::Game(QGraphicsView* parrent)
    : QGraphicsScene(parrent),
    matrixOfLevel(26, QVector<int>(26))
{
    _parrent = parrent;
    this->setSceneRect(0, 0, _sizeOfScene, _sizeOfScene);
    setBackgroundBrush(QColor(0, 0, 0));

    _levelTicker.setInterval(500);
    QObject::connect(&_levelTicker, &QTimer::timeout,
                     this, &Game::update);
}

void Game::abort()
{
    _levelTicker.stop();

    this->clear();
}


void Game::initializeLevel(int level)
{
    loadLevel(level);

    printMap(matrixOfLevel);

    //createNpcs(); TODO Ivana: implementiraj

    //    // Add boost to the scene
    //    Boost *booster = new Boost(0, 0);
    //    _scene->addItem(booster);

    //    //START OF TEST1
    //    Player *igrac1 = new Player(1);
    //    Player *igrac2 = new Player(2);
    //    _scene->addItem(igrac1);
    //    _scene->addItem(igrac2);
    //    scene->update();
    //    //END OF TEST1

//    _levelTicker.start();
    update();
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

void Game::update()
{
    //do the changes

    _parrent->update();
}

void Game::countBonusScore(int typeOfKilledEnemy)
{
    if(typeOfKilledEnemy > 4 || typeOfKilledEnemy < 1)
    {
        qDebug() << "potkrala se pogresna vrednost, prosledjen redni br tenka vrste koja ne postoji";
                    return ;
    }
    _bonusScore += typeOfKilledEnemy;
}


void Game::printMap(const QVector<QVector<int>> matrixOfLevel)
{
    // Creating blocks based ond matrixOfLevel
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if (matrixOfLevel[i][j] == 1) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::brick, ":/blocks/brick.png");
                this->addItem(b);
            }
            else if (matrixOfLevel[i][j] == 2) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/stone.png");
                this->addItem(b);
            }
            else if (matrixOfLevel[i][j] == 3) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/water.png");
                this->addItem(b);
            }
            else if (matrixOfLevel[i][j] == 4) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/bush.png");
                this->addItem(b);
            }
        }
    }
    // Add phoenix to the scene
    Block *phoenix = new Block(300, 600, ":/blocks/phoenix.png");
    this->addItem(phoenix);
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

    //if(event->key() == Qt::Key_H)
    //    _help->isHidden() ? showHelp() : hideHelp();

    if(event->key() == Qt::Key_P)
    {
        //TODO: add pause
    }

    if(event->key() == Qt::Key_Escape)
    {
        //TODO: add backToMenu
    }
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
