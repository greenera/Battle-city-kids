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


//Todo: pri prebacivanju '_scene' zameniti za 'this'
void GameWidget::printMap(const QVector<QVector<int>> matrixOfLevel) const {
    // Creating blocks based ond matrixOfLevel
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if (matrixOfLevel[i][j] == 1) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::brick, ":/blocks/brick.png");
                _scene->addItem(b);
            }
            else if (matrixOfLevel[i][j] == 2) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/stone.png");
                _scene->addItem(b);
            }
            else if (matrixOfLevel[i][j] == 3) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/water.png");
                _scene->addItem(b);
            }
            else if (matrixOfLevel[i][j] == 4) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/bush.png");
                _scene->addItem(b);
            }
        }
    }
    // Add phoenix to the scene
    Block *phoenix = new Block(300, 600, ":/blocks/phoenix.png");
    _scene->addItem(phoenix);
    //_ui->activegame->setScene(_scene);
    //_scene->update();
}
