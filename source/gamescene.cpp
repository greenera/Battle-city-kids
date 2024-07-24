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
      _npcVector(4),
      matrixOfLevel(26, QVector<int>(26))
{
    _parrent = parrent;
    _parrent->setFocusPolicy(Qt::StrongFocus);

    setSceneRect(0, 0, _sizeOfScene, _sizeOfScene);
    setBackgroundBrush(QColor(0, 0, 0));

    _levelTicker.setInterval(50);
    QObject::connect(&_levelTicker, &QTimer::timeout,
                     this, &GameScene::update);

    connect(&_npcCreating, &QTimer::timeout,
            this, &GameScene::npcFactory);

    setFocus();
}

GameScene::~GameScene()
{
    qDeleteAll(_npcs);
    qDeleteAll(_bullets);
}


void GameScene::abort()
{
    _levelTicker.stop();
    _npcCreating.stop();
    _shooting1.stop();
    _shooting2.stop();

    qDeleteAll(_npcs);
    qDeleteAll(_bullets);
    _npcs.clear();
    _bullets.clear();

    clear();
}

void GameScene::resume()
{
    _parrent->setFocus();
    _levelTicker.start();
    _npcCreating.start();
    _shooting1.start();
    _shooting2.start();
}


void GameScene::initializeLevel(int level, int numOfPlayers)
{
    _numOfLevel = level;
    _parrent->setFocus();

    loadLevel(level);
    printMap(matrixOfLevel);

    _npcCreating.setInterval(4000 - 120 * level);

    for (int i = 0; i < 3; i++)
    {
        _npcVector[i]--;
        _npcs.append(new Npc(i * 300, 0, i+1));
        addItem(_npcs.back());

        emit npcCreated(20 - i);
    }
    Player *igrac1 = new Player(1);
    _players[0] = igrac1;
    addItem(igrac1);

    igrac1->setDown(false);
    igrac1->setUp(false);
    igrac1->setLeft(false);
    igrac1->setRight(false);

    _players[0]->shootingEnabled = true;
    _shooting1.setInterval(2000);
    _shooting1.setSingleShot(true);
    QObject::connect(&_shooting1, &QTimer::timeout,
                     this, [&](){_players[0]->shootingEnabled = true;});

    if (--numOfPlayers > 0)
    {
        Player *igrac2 = new Player(2);
        addItem(igrac2);
        _players[1] = igrac2;

        igrac2->setDown(false);
        igrac2->setUp(false);
        igrac2->setLeft(false);
        igrac2->setRight(false);

        _players[1]->shootingEnabled = true;
        _shooting2.setInterval(2000);
        _shooting2.setSingleShot(true);
        QObject::connect(&_shooting2, &QTimer::timeout,
                         this, [&](){_players[1]->shootingEnabled = true;});
    }
    else
        _players[1] = nullptr;

    _npcCreating.start();
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

            if(c == '\n' || c == '\r') {
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
    if(_players[0] != nullptr)
        _players[0]->colisionDetection();
    if(_players[1] != nullptr)
        _players[1]->colisionDetection();

    foreach(Npc* n, _npcs)
    {
        n->colisionDetection();
    }

    int index = 0;
    foreach(Bullet* b, _bullets) {
        QList<QGraphicsItem*> list = b->collidingItems();
        if (list.size() > 0)
        {
            foreach(QGraphicsItem* i , list)
            {
                removeItem(i);
                if (i == _phoenix)
                {
                    _npcCreating.stop();
                    _shooting1.stop();
                    _shooting2.stop();
                    _levelTicker.stop();
                    emit exitRequested();
                }
            }
            delete b;
            if(index < _bullets.length())
                _bullets.remove(index);
        }
        index++;
    }

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
                addItem(b);
            }
            else if (matrixOfLevel[i][j] == 2) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/stone.png");
                addItem(b);
            }
            else if (matrixOfLevel[i][j] == 3) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/water.png");
                addItem(b);
            }
            else if (matrixOfLevel[i][j] == 4) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/bush.png");
                addItem(b);
            }
        }
    }
    // Add phoenix to the scene
    _phoenix = new Block(300, 600, ":/blocks/phoenix.png");
    addItem(_phoenix);
}

int GameScene::roulet()
{
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += _npcVector[i];
    }
    //izaberi random broj 0-sum
    int choosen = _generator.bounded(sum);
    //prolazi kroz petlju ponovo
    //i vidi koji je na tom mestu
    int sum2 = 0;
    for (int i = 0; i < 4; i++)
    {
        sum2 += _npcVector[i];
        if(choosen < sum2)
            return i;
    }
    return sum; //actualy never happen
}

void GameScene::moveBullets()
{
    foreach(Bullet* b, _bullets)
        b->moveBullet();
}


void GameScene::npcFactory()
{
    if (_npcVector.length() >= _numOfLevel + 5)
        return ;

    //izaberi jednog (rulet metodom)
    int npcType = roulet();

    //izberi bazu
    int baza = _generator.bounded(2);
    int sum = 0;
    for (int a : _npcVector)
        sum += a;

    //napravi npc na toj poziciji
    Npc * b = new Npc(baza * 300, 0, 2 + npcType);
    _npcs.append(b);
    addItem(b);
//    b->_shootTimer.start();

    //emituj hajdovanje labele
    emit npcCreated(sum);
    _npcVector[npcType]--;

    //zaustavi tajmer ako nema vise tenkova za crtanje
    if (sum == 0)
        _npcCreating.stop();
}

void GameScene::movePlayers()
{
    if (_players[0] != nullptr)
    {
        _players[0]->move();
    }
    if (_players[1] != nullptr)
    {
        _players[1]->move();
    }
}


void GameScene::moveNpcs()
{
    foreach(Npc* n, _npcs)
    {
        if (n->shootingEnabled == true) {
            _bullets.append(n->shoot());
            addItem(_bullets.back());
        }
        if(n != nullptr)
        {
            if (n->_npcDirection == 1)
                n->setLeft(true);
            else if(n->_npcDirection == 3)
                n->setRight(true);
            else if(n->_npcDirection == 2)
                n->setUp(true);
            else
                n->setDown(true);

            //n->_npcDirection++;
            //if(n->_npcDirection > 15000)
                //n->_npcDirection = 0;

            n->move();
        }
    }
}

//TODO: add macros for 501
void GameScene::onStar(int playerNum)
{
    if (playerNum == 1)
    {
        int newValue = _shooting1.interval() - 501;
        _shooting1.setInterval(newValue < 0 ? 500 : newValue);
    }
    else
    {
        int newValue = _shooting2.interval() - 501;
        _shooting2.setInterval(newValue < 0 ? 500 : newValue);
    }
}

void GameScene::onBomb()
{
    foreach(Npc* n, _npcs)
        delete n;

    _npcs.clear();
}


void GameScene::keyPressEvent(QKeyEvent *event)
{
    //consider player1
    if(_players[0] != nullptr)
    {
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
        if(event->key() == Qt::Key_F) {
            if (_players[0]->shootingEnabled == true) {
                _shooting1.start();
                _bullets.append(_players[0]->shoot());
                addItem(_bullets.back());
            }
        }
    }

    //consider player2
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
        if(event->key() == Qt::Key_L) {
            if (_players[1]->shootingEnabled == true) {
                _shooting2.start();
                _bullets.append(_players[1]->shoot());
                addItem(_bullets.back());
            }
        }
    }

    if(event->key() == Qt::Key_H)
    {
        _npcCreating.stop();
        _shooting1.stop();
        _shooting2.stop();
        _levelTicker.stop();
        emit helpRequested();
    }
    if(event->key() == Qt::Key_P)
    {
        _npcCreating.stop();
        _shooting1.stop();
        _shooting2.stop();
        _levelTicker.stop();
        emit pauseRequested();
    }

    if(event->key() == Qt::Key_Escape)
    {
        _npcCreating.stop();
        _shooting1.stop();
        _shooting2.stop();
        _levelTicker.stop();
        emit exitRequested();
    }

    if(event->key() == Qt::Key_T)
    { //this one is used for testing
        emit killed();
        onBomb();
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if(_players[0] != nullptr) {
        //consider 'w' 'a' 's' and 'd'
        if (event->key() == Qt::Key_W)
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


