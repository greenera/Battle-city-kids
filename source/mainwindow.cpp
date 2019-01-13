#include "ui_mainwindow.h"
#include "include/mainwindow.h"

#include <QDebug>

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 * \details Should have one big field called Presented.
 * In Presented will be loaded:
 *  - menu (for choosing options)
 *  - reached level (in wich game will play)
 *  - help page (with instructions how to play)
 * This class should have information:
 *  - about first level widget
 *  - about menu widget
 *  - about help page
 * Allways, only one of these should be visible.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    //add all three widgets
    _menu = new Menu();
    _ui->presented->addWidget(_menu);

    _gameWrapper = new GameProxy(this);
    _gameWidget = _gameWrapper->getGameWidget();
    _ui->presented->addWidget(_gameWidget);

    _help = new Help();
    _ui->presented->addWidget(_help);

    //connect
    QObject::connect(_gameWrapper, &GameProxy::gameOver,
                     this, [&] () {
        _gameWidget->setHidden(true);
        _menu->setHidden(false);
        _inGame = false;
    });

    QObject::connect(_menu->getStartButton(), &QPushButton::clicked,
                     this, [&] (){
        _gameWrapper->initializeGame();
        _gameWidget->setHidden(false);
        _menu->setHidden(true);
        _inGame = true;
    });

    QObject::connect(_gameWidget->getGameScene(), &GameScene::helpRequested,
                     this, [&](){
        qDebug() << "in gameWindow";
        this->setFocus();
        showHelp();
    });

    //set current state
    _gameWidget->setHidden(true);
    _help->setHidden(true);

    _inGame = false;
    this->setFocus(); //!< this is important for responding to keyboard
}

/*!
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::showHelp()
{
    _gameWidget->setHidden(true);
    _menu->setHidden(true);
    _help->setHidden(false);
}

void MainWindow::hideHelp()
{
    _gameWidget->setHidden(!_inGame);
    _menu->setHidden(_inGame);
    _help->setHidden(true);
    if(_inGame)
    {
        _gameWidget->getGameScene()->resume();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_H)
        _help->isHidden() ? showHelp() : hideHelp();
}
