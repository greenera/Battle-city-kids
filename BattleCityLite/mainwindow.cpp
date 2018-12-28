#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>

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
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(-300, -300, 600, 600);

    Boost *booster = new Boost(0, 0);
    scene->addItem(booster);

    _ui->graphicsView->setScene(scene);

    scene->update();
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

void MainWindow::connectSlotsAndSignals(){
    //TODO odraditi konekcije za hvatanje akcija
}
