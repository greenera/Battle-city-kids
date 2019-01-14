#include "include/gamescene.h"
#include <QFile>

#include <QDebug>

/**
 * @brief Game::Game
 * @param parrent
 * \details Scena koja predstavlja igru. Tu se regulise igra u okviru nivoa.
 * Trebalo bi preimenovati je u levelScene, takodje prebaciti sve sto ima veze sa scenom ovde.
 */
GameScene::GameScene(QGraphicsView* parrent)
    : QGraphicsScene(parrent),
    matrixOfLevel(26, QVector<int>(26)),
    _npcVector(4), _playerStatus(2)
{
    _parrent = parrent;
    _parrent->setFocusPolicy(Qt::StrongFocus);

    this->setSceneRect(0, 0, _sizeOfScene, _sizeOfScene);
    setBackgroundBrush(QColor(0, 0, 0));

    _levelTicker.setInterval(50);
    QObject::connect(&_levelTicker, &QTimer::timeout,
                     this, &GameScene::update);

    setFocus();
}

void GameScene::abort()
{
    _levelTicker.stop();
    this->clear();
}

void GameScene::resume()
{
    _parrent->setFocus();
    _levelTicker.start();
}


void GameScene::initializeLevel(int level, int numOfPlayers)
{
    _parrent->setFocus();

    loadLevel(level);
    printMap(matrixOfLevel);

    //createNpcs(); TODO Ivana: implementiraj

    Player *igrac1 = new Player(1);
    _players[0] = igrac1;
    _playerStatus[0] = true;
    _playerStatus[1] = false;
    this->addItem(igrac1);
    igrac1->setDown(false);
    igrac1->setUp(false);
    igrac1->setLeft(false);
    igrac1->setRight(false);
    _players[0]->shootingEnabled = true;
    _shooting.setInterval(2000);
    _shooting.setSingleShot(true);
    QObject::connect(&_shooting, &QTimer::timeout, this, [&](){_players[0]->shootingEnabled = true;});


    if (--numOfPlayers > 0)
    {
        Player *igrac2 = new Player(2);
        this->addItem(igrac2);
        _players[1] = igrac2;
        _playerStatus[1] = true;

        igrac2->setDown(false);
        igrac2->setUp(false);
        igrac2->setLeft(false);
        igrac2->setRight(false);
        _players[1]->shootingEnabled = true;
        _shooting.setInterval(2000);
        _shooting.setSingleShot(true);
        QObject::connect(&_shooting, &QTimer::timeout, this, [&](){_players[1]->shootingEnabled = true;});
    }

    _levelTicker.start();
}


void GameScene::loadLevel(int levelNum)
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
            matrixOfLevel[i][j] = c - '0'; // Write data into matrix
        }
    }

    // 20 npcs per level, 4 types of tanks
    file.readLine();
    QString line = file.readLine();
    QStringList list = line.split(" ");
    _npcVector[0] = list.at(0).toInt();
    _npcVector[1] = list.at(1).toInt();
    _npcVector[2] = list.at(2).toInt();
    _npcVector[3] = list.at(3).toInt();

    file.close(); // Close the file
}

void GameScene::update()
{
    //change position of dinamic objects
    movePlayers();
    moveNpcs();
    moveBullets();

    //do the changes
    if(_playerStatus[0] == true)
        _players[0]->colisionDetection();
    if(_playerStatus[1] == true)
        _players[1]->colisionDetection();

    _parrent->update();
}

void GameScene::countBonusScore(int typeOfKilledEnemy)
{
    if(typeOfKilledEnemy > 4 || typeOfKilledEnemy < 1)
    {
        qDebug() << "potkrala se pogresna vrednost, prosledjen redni br tenka vrste koja ne postoji";
        return ;
    }
    _bonusScore += typeOfKilledEnemy;
}

void GameScene::printMap(const QVector<QVector<int>> matrixOfLevel)
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

void GameScene::movePlayers()
{
    if (_playerStatus[0] == true)
    {
        _players[0]->move();
    }
    if (_playerStatus[1] == true)
    {
        _players[1]->move();
    }
}

void GameScene::moveNpcs()
{

}

void GameScene::moveBullets()
{
    foreach(Bullet* b, bullets)
            b->moveBullet();
}



//TODO: srediti da ne moze da se krece ukoso
void GameScene::keyPressEvent(QKeyEvent *event)
{
    //consider 'w' 'a' 's' and 'd'
    if(_playerStatus[0] == true)
    {
        qDebug() << "in players one area";
        if(event->key() == Qt::Key_W)
        {
            qDebug() << "in player1 up";
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

        if(event->key() == Qt::Key_F) {
                if (_players[0]->shootingEnabled == true) {
                    _shooting.start();
                    bullets.append(_players[0]->shoot());
                    this->addItem(bullets.back());
                }
        }
    }

    //consider 'up' 'down' 'left' and 'right'
    if(_playerStatus[1] == true)
    {
        qDebug() << "in player2s area";
        if(event->key() == Qt::Key_Up)
        {
            qDebug() << "in player2 up";
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
        if(event->key() == Qt::Key_L) {
                if (_players[1]->shootingEnabled == true) {
                    _shooting.start();
                    bullets.append(_players[1]->shoot());
                    this->addItem(bullets.back());
                }
        }
    }

    if(event->key() == Qt::Key_H)
    {
        qDebug() << "been there";
        _levelTicker.stop();
        emit helpRequested();
    }
    if(event->key() == Qt::Key_P)
    {
        _levelTicker.stop();
        emit pauseRequested();
    }

    if(event->key() == Qt::Key_Escape)
    {
        //TODO: add backToMenu
        _levelTicker.stop();
        emit exitRequested();
    }

    if(event->key() == Qt::Key_T)
    { //this one is used for testing
        emit killed();
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if(_playerStatus[0] == true) {
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
}
    //consider 'up' 'down' 'left' and 'right'
    if(_playerStatus[1] == true)
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
