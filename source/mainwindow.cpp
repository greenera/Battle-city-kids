#include "include/mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include "include/game.h"
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
 * Allways, only one of these should be visible.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);


    //add both menu and game widget
    _menu = new Menu();
    _ui->presented->addWidget(_menu);

    auto pom = new GameWrapper(); //from this moment game and gameWidget are connected
    _gameWidget = pom->getGameWidget();
    _ui->presented->addWidget(_gameWidget);

    //this->setStyleSheet("background-color: black;");

    //set one hidden
    _gameWidget->setHidden(true);

    connectSlotsAndSignals();

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

void MainWindow::connectSlotsAndSignals()
{
    QObject::connect(_menu->getStartButton(), &QPushButton::clicked, this, &MainWindow::startGame);
}

void MainWindow::startGame()
{
    _menu->setHidden(true);
    //TODO: treba inicijalizovati igru na pocetak pre prikazivanja
    _gameWidget->setHidden(false);
}
