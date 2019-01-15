#include "include/gamewidget.h"
#include "ui_gamewidget.h"

#include <include/player.h>

/**
 * @brief GameWidget::GameWidget
 * @param parent
 * @param scene
 * \details ovde bi trebalo da se pravi nova igra.
 */

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::GameWidget)
{
    _ui->setupUi(this);

    _scene = new GameScene(_ui->activegame);
    _ui->activegame->setScene(_scene);

    //set hole stopwatch thing
    _refreshingLabel.setInterval(1000);
    resetTimeLabel();

    setFocusPolicy(Qt::StrongFocus);

    QObject::connect(&_refreshingLabel, &QTimer::timeout,
                     this, &GameWidget::setTimeLabel);

    QObject::connect(_scene, &GameScene::endOfLevel,
                     this, &GameWidget::onEndOfLevel);

    QObject::connect(_scene, &GameScene::npcCreated,
                     this, &GameWidget::hideTank);

    _small_tenk = QPixmap(":/small_tank/small_npc.jpg");
    initSmallTankText();
}

GameWidget::~GameWidget()
{
    delete _ui;
}

void GameWidget::initializeLevel(int level, int numOfPlayers)
{
    //sredi svoje stvari
    setLevelName(level);
    _refreshingLabel.stop(); //!< stop so it doesnt crash when try at the same time to change text
    resetTimeLabel(); //!< initialize value that is shown
    _refreshingLabel.start(); //!< start again
    setVisibleSmallTank();

    //kaze sceni da se inicijalizuje
    _ui->activegame->scene()->clear();
    _scene->initializeLevel(level,numOfPlayers);
}


GameScene *GameWidget::getGameScene()
{
    return _scene;
}

void GameWidget::setLifeInformation(int num)
{
    _ui->livesInfo->setText("Lives: \n" + QString::number(num));
}

void GameWidget::abort()
{
    //sredi svoje stvari
    _refreshingLabel.stop();

    //sredi scenu
    _scene->abort();
}

void GameWidget::onEndOfLevel(double forward)
{
    _refreshingLabel.stop();

    emit endOfLevel(forward/_minutes);
}

void GameWidget::setLevelName(int level)
{
    _ui->horizontalStatus->setText("Level: " + QString::number(level));
}

void GameWidget::resetTimeLabel()
{
    _ui->timeLabel->setText("0m 0s");
    _minutes = _sec = 0;
}

void GameWidget::setTimeLabel()
{
    if (isHidden())
        return ;

    ++_sec;
    if (_sec >= 60)
    {
        _sec = 0;
        ++_minutes;
    }

    _ui->timeLabel->setText(QString::number(_minutes) + "m " +
                            QString::number(_sec) + "s");
}

void GameWidget::setVisibleSmallTank()
{
    _ui->small_tank_1->setHidden(false);
    _ui->small_tank_2->setHidden(false);
    _ui->small_tank_3->setHidden(false);
    _ui->small_tank_4->setHidden(false);
    _ui->small_tank_5->setHidden(false);
    _ui->small_tank_6->setHidden(false);
    _ui->small_tank_7->setHidden(false);
    _ui->small_tank_8->setHidden(false);
    _ui->small_tank_9->setHidden(false);
    _ui->small_tank_10->setHidden(false);
    _ui->small_tank_11->setHidden(false);
    _ui->small_tank_12->setHidden(false);
    _ui->small_tank_13->setHidden(false);
    _ui->small_tank_14->setHidden(false);
    _ui->small_tank_15->setHidden(false);
    _ui->small_tank_16->setHidden(false);
    _ui->small_tank_17->setHidden(false);
    _ui->small_tank_18->setHidden(false);
    _ui->small_tank_19->setHidden(false);
    _ui->small_tank_20->setHidden(false);
}

void GameWidget::initSmallTankText()
{
    _ui->small_tank_1->setPixmap(_small_tenk);
    _ui->small_tank_2->setPixmap(_small_tenk);
    _ui->small_tank_3->setPixmap(_small_tenk);
    _ui->small_tank_4->setPixmap(_small_tenk);
    _ui->small_tank_5->setPixmap(_small_tenk);
    _ui->small_tank_6->setPixmap(_small_tenk);
    _ui->small_tank_7->setPixmap(_small_tenk);
    _ui->small_tank_8->setPixmap(_small_tenk);
    _ui->small_tank_9->setPixmap(_small_tenk);
    _ui->small_tank_10->setPixmap(_small_tenk);
    _ui->small_tank_11->setPixmap(_small_tenk);
    _ui->small_tank_12->setPixmap(_small_tenk);
    _ui->small_tank_13->setPixmap(_small_tenk);
    _ui->small_tank_14->setPixmap(_small_tenk);
    _ui->small_tank_15->setPixmap(_small_tenk);
    _ui->small_tank_16->setPixmap(_small_tenk);
    _ui->small_tank_17->setPixmap(_small_tenk);
    _ui->small_tank_18->setPixmap(_small_tenk);
    _ui->small_tank_19->setPixmap(_small_tenk);
    _ui->small_tank_20->setPixmap(_small_tenk);
}

void GameWidget::hideTank(int num)
{
    if (num == 1)
        _ui->small_tank_1->setHidden(true);
    if (num == 2)
        _ui->small_tank_2->setHidden(true);
    if (num == 3)
        _ui->small_tank_3->setHidden(true);
    if (num == 4)
        _ui->small_tank_4->setHidden(true);
    if (num == 5)
        _ui->small_tank_5->setHidden(true);
    if (num == 6)
        _ui->small_tank_6->setHidden(true);
    if (num == 7)
        _ui->small_tank_7->setHidden(true);
    if (num == 8)
        _ui->small_tank_8->setHidden(true);
    if (num == 9)
        _ui->small_tank_9->setHidden(true);
    if (num == 10)
        _ui->small_tank_10->setHidden(true);
    if (num == 11)
        _ui->small_tank_11->setHidden(true);
    if (num == 12)
        _ui->small_tank_12->setHidden(true);
    if (num == 13)
        _ui->small_tank_13->setHidden(true);
    if (num == 14)
        _ui->small_tank_14->setHidden(true);
    if (num == 15)
        _ui->small_tank_15->setHidden(true);
    if (num == 16)
        _ui->small_tank_16->setHidden(true);
    if (num == 17)
        _ui->small_tank_17->setHidden(true);
    if (num == 18)
        _ui->small_tank_18->setHidden(true);
    if (num == 19)
        _ui->small_tank_19->setHidden(true);
    if (num == 20)
        _ui->small_tank_20->setHidden(true);
}
