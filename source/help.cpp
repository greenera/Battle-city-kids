#include "include/help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    ui->label->setPixmap(_texture);

}

Help::~Help()
{
    delete ui;
}
