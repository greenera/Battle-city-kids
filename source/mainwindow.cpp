#include "ui_mainwindow.h"
#include "include/mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include "include/gamescene.h"
#include "include/block.h"

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 * \details Should have one big field called Presented.
 * In Presented will be loaded:
 *  - menu (for choosing options)
 *  - reached level (in wich game will play)
 * This class should have information:
 *  -about first level widget
 *  -about menu widget
 * Always, only one of these should be visible.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    //add both menu and game widget
    _menu = new Menu();
    _ui->presented->addWidget(_menu);

    auto _gameWrapper = new GameProxy(this);
    _gameWidget = _gameWrapper->getGameWidget();
    _ui->presented->addWidget(_gameWidget);

    //connect to gameWraper
    QObject::connect(_gameWrapper, &GameProxy::gameOver,
                     this, [&] () {
        _gameWidget->setHidden(true);
        _menu->setHidden(false);
    });

    QObject::connect(_menu->getStartButton(), &QPushButton::clicked,
                     this, [&] (){
        _menu->setHidden(true);
        _gameWidget->setHidden(false);
    });

    //this->setStyleSheet("background-color: black;");

    //set one hidden
    _gameWidget->setHidden(true);
}

/*!
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::restartGame(){
    //TODO implementirati ponovno pokretanje igre
}

void MainWindow::pauseGame(){
    //TODO implementirati pauzu u igri
}

void MainWindow::exitLevel(){
    //TODO implementirati izlazak iz igre
}

void MainWindow::showHelp(){
    //TODO implementirati prikazivanje pomoci
}

void MainWindow::hideHelp(){
    //TODO implementirati sakrivanje pomoci
}
