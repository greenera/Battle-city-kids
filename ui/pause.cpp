#include "pause.h"
#include "ui_pause.h"

Pause::Pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:black; color: orange");
}

Pause::~Pause()
{
    delete ui;
}
