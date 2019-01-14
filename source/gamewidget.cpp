#include "include/gamewidget.h"
#include "ui_gamewidget.h"

#include <include/player.h>

/**
 * @brief GameWidget::GameWidget
 * @param parent
 * @param scene
 * \details ovde bi trebalo da se pravi nova igra.
 * Treba da prikazuje sve aktivne informacije (koje dobija od gameWrapper-a).
 * potrebne funkcije:
 * void setLevelNumber(int num);
 * void setNumOfEnemies(int num);
 * void setInformacija3()....
 *
 * trebalo bi izbaciti sve funkcije vezane za scenu odavde.
 * i implementirati jedino funkciju public void setScene(QGraphicsScene * scena){_ui->activegame->setScene(scene);}
 * i nju treba zvati iz gameWrapera pri kreiranu scene i widget-a
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

    //set some game rule
    QObject::connect(_scene, &GameScene::endOfLevel,
                     this, &GameWidget::onEndOfLevel);
}

GameWidget::~GameWidget()
{
    delete _ui;
}

void GameWidget::initializeLevel(int level)
{
    //sredi svoje stvari
    setLevelName(level);
    _refreshingLabel.stop(); //!< stop so it doesnt crash when try at the same time to change text
    resetTimeLabel(); //!< initialize value that is shown
    _refreshingLabel.start(); //!< start again

    //kaze sceni da se inicijalizuje
    _ui->activegame->scene()->clear();
    _scene->initializeLevel(2);

    _small_tenk = QPixmap(":/small_tank/small_npc.jpg");
    initSmallTankText();
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
    if (this->isHidden())
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
