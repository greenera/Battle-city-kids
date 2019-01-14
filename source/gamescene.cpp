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
      _npcVector(4)
{
    _parrent = parrent;
    _parrent->setFocusPolicy(Qt::StrongFocus);

    this->setSceneRect(0, 0, _sizeOfScene, _sizeOfScene);
    setBackgroundBrush(QColor(0, 0, 0));

    _levelTicker.setInterval(50);
    QObject::connect(&_levelTicker, &QTimer::timeout,
                     this, &GameScene::update);

    connect(&_npcCreating, &QTimer::timeout,
            this, &GameScene::npcFactory);

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

    _npcCreating.setInterval(4000 - 120 * level);
    _npcCreating.start();

    Player *igrac1 = new Player(1);
    _players[0] = igrac1;
    this->addItem(igrac1);

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
        this->addItem(igrac2);
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

    //move bulltets
    foreach(Bullet* b, bullets)
        b->moveBullet();

    //do the changes
    if(_players[0] != nullptr)
        _players[0]->colisionDetection();
    if(_players[1] != nullptr)
        _players[1]->colisionDetection();

    _parrent->update(); //!< should be at end of function
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

//TODO: treba da se umanji sum

void GameScene::npcFactory()
{
    //izaberi jednog (rulet metodom)
    int npcType = roulet();

    //izberi bazu
    int baza = _generator.bounded(2);

    int sum = 0;
    for (int a : _npcVector)
        sum += a;

    //napravi npc na toj poziciji
    _npcs.append(new Npc(baza * 300, 0, 2));
    this->addItem(_npcs.back());

    //emituj hajdovanje labele
    emit npcCreated(sum);

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
                _shooting1.start();
                bullets.append(_players[0]->shoot());
                this->addItem(bullets.back());
            }
        }
    }

    //consider player2
    if(_players[1] != nullptr)
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
                _shooting2.start();
                bullets.append(_players[1]->shoot());
                this->addItem(bullets.back());
            }
        }
    }

    if(event->key() == Qt::Key_H)
    {
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
        onStar(1);
        onBomb();
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
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


