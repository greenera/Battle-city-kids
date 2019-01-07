#include "include/gamewidget.h"
#include "ui_gamewidget.h"



GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::GameWidget)
{
    _ui->setupUi(this);
    //initializing scene
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, 2*_sizeOfScene, 2*_sizeOfScene);
    _scene->setBackgroundBrush(QColor(0, 0, 0));


    // Add boost to the scene
    Boost *booster = new Boost(0, 0);
    _scene->addItem(booster);

    _ui->activegame->setScene(_scene);
    _scene->update();
}

GameWidget::~GameWidget()
{
    delete _ui;
}

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
    _ui->activegame->setScene(_scene);
    _scene->update();
}
