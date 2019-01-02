#include "include/gamewidget.h"
#include "ui_gamewidget.h"
#include "include/boost.h"


GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::GameWidget)
{
    _ui->setupUi(this);


    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(-_sizeOfScene, -_sizeOfScene, _sizeOfScene, _sizeOfScene);

    Boost *booster = new Boost(0, 0);
    scene->addItem(booster);
    _ui->activegame->setScene(scene);
    scene->update();
}

GameWidget::~GameWidget()
{
    delete _ui;
}
