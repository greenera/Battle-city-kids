#include "include/menu.h"
#include <QPainter>
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Menu)
{
    _ui->setupUi(this);

    _ui->label_2->setPixmap(QPixmap(":/main_menu/battle-city-name.png"));

    connectSlotsAndSignals();
}

//Menu::~Menu()
//{
//    delete _ui;
//}

QPushButton *Menu::getStartButton()
{
    return _ui->play_button;
}

void Menu::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case(Qt::Key_Escape):
            exit(EXIT_SUCCESS);
    }
}

void Menu::startGame(){

}

void Menu::exitProgram()
{
    exit(EXIT_SUCCESS);
}

void Menu::connectSlotsAndSignals()
{
    connect(_ui->exit_button, SIGNAL(clicked()), this, SLOT(exitProgram()));
    connect(_ui->play_button, SIGNAL(clicked()), this, SLOT(startGame()));
}
