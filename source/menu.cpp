#include "include/menu.h"
#include <QPainter>
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Menu)
{
    _ui->setupUi(this);

    _ui->label_2->setPixmap(QPixmap(":/main_menu/battle-city-name.png"));
    _ui->highscore_label->setText(loadScore());

    connect(_ui->exit_button, SIGNAL(clicked()), this, SLOT(exitProgram()));
}

Menu::~Menu()
{
    delete _ui;
}

QPushButton *Menu::getStartButton()
{
    return _ui->play_button;
}

QPushButton *Menu::getStartButton2()
{
    return _ui->play_button2;
}

void Menu::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case(Qt::Key_Escape):
            exit(EXIT_SUCCESS);
    }
}

void Menu::exitProgram()
{
    exit(EXIT_SUCCESS);
}

QString Menu::loadScore() {
    QFile file("resources/score.txt");
    file.open(QIODevice::ReadOnly);
    QString score = file.readLine().trimmed();
    return "HIGHSCORE: " + score;
}
