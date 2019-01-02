#include "include/mainwindow.h"

#include <QDebug>
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
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    //Loading level
    Game g;
    g.loadLevel(2);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 900, 650);

    // Creating blocks based ond matrixOfLevel
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            qDebug() << g.matrixOfLevel[i][j];
            if (g.matrixOfLevel[i][j] == 1) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::brick, ":/blocks/brick.png");
                scene->addItem(b);
            }
            else if (g.matrixOfLevel[i][j] == 2) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/stone.png");
                scene->addItem(b);
            }
            else if (g.matrixOfLevel[i][j] == 3) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/water.png");
                scene->addItem(b);
            }
            else if (g.matrixOfLevel[i][j] == 4) {
                Block *b = new Block(25*j, 25*i, true, Block::Material::stone, ":/blocks/bush.png");
                scene->addItem(b);
            }
        }
    }
    // Add phoenix to the scene
    Block *phoenix = new Block(300, 600, ":/blocks/base.png");
    scene->addItem(phoenix);

    // Add boost to the scene
    Boost *booster = new Boost(350, 150);
    scene->addItem(booster);

    _ui->graphicsView->setScene(scene);
    _ui->graphicsView->setFixedSize(900, 650);
    _ui->graphicsView->setFrameStyle(0);
    _ui->graphicsView->setBackgroundBrush(QColor(0, 0, 0));

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
