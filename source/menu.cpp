#include "include/menu.h"
#include <QPainter>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Menu)
{
    _ui->setupUi(this);


    connectSlotsAndSignals();
}

Menu::~Menu()
{
    delete _ui;
}


void Menu::startGame(){
    //TODO implementirati zapocinjanje nove igre
}

void Menu::exitProgram(){
    exit(EXIT_SUCCESS);
}

void Menu::connectSlotsAndSignals(){
    connect(_ui->exit_button, SIGNAL(clicked()), this, SLOT(exitProgram()));
}
