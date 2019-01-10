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

GameWidget::GameWidget(QWidget *parent, QGraphicsScene *scene) :
    QWidget(parent),
    _ui(new Ui::GameWidget)
{
    _ui->setupUi(this);

    _ui->activegame->setScene(scene);
    _scene = scene;

    // Add boost to the scene
    Boost *booster = new Boost(0, 0);
    _scene->addItem(booster);

    //START OF TEST1
    Player *igrac1 = new Player(1);
    Player *igrac2 = new Player(2);
    _scene->addItem(igrac1);
    _scene->addItem(igrac2);
    //END OF TEST1

    scene->update();
}

GameWidget::~GameWidget()
{
    delete _ui;
}


