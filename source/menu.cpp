#include "include/menu.h"
#include <QPainter>
#include "ui_menu.h"

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

QPushButton *Menu::getStartButton()
{
    return _ui->play_button;
}

void Menu::exitProgram()
{
    exit(EXIT_SUCCESS);
}

void Menu::connectSlotsAndSignals()
{
    connect(_ui->exit_button, SIGNAL(clicked()), this, SLOT(exitProgram()));
}
