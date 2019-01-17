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
    _inGame(false),
    _help(),
    _menu(),
    _gameWidget(),
    _gameProxy(&_gameWidget),
  _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    //add all three widgets
    _ui->presented->addWidget(&_menu);
    _ui->presented->addWidget(&_gameWidget);
    _ui->presented->addWidget(&_help);

    //set sound effect
    _levelStarter.setSource(QUrl::fromLocalFile("resources/music.wav"));

    _levelStarter.setLoopCount(1);

    //connect
    connect();

    //set current state
    _gameWidget.setHidden(true);
    _help.setHidden(true);

    _levelStarter.play();

    setStyleSheet("background-color:black; color:orange;");
    setFocus(); //!< this is important for responding to keyboard
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
    _gameWidget.setHidden(true);
    _menu.setHidden(true);
    _help.setHidden(false);
}

void MainWindow::hideHelp()
{
    _gameWidget.setHidden(!_inGame);
    _menu.setHidden(_inGame);
    _help.setHidden(true);
    if(_inGame)
    {
        _gameWidget.getGameScene()->resume();
    }
}

void MainWindow::showPause()
{
    _gameWidget.setHidden(true);
    _menu.setHidden(true);
    _help.setHidden(true);
}

void MainWindow::hidePause()
{
    _gameWidget.setHidden(!_inGame);
    _menu.setHidden(_inGame);
    _help.setHidden(true);
    if(_inGame)
    {
        _gameWidget.getGameScene()->resume();
    }
}

void MainWindow::connect()
{
    QObject::connect(&_gameProxy, &GameProxy::gameOver,
                     this, [&] () {
        _gameWidget.setHidden(true);
        _menu.setHidden(false);
        _inGame = false;
    });

    QObject::connect(_menu.getStartButton(), &QPushButton::clicked,
                     this, [&] (){
        _levelStarter.play();
        _gameProxy.initializeGame(1);
        _gameWidget.setHidden(false);
        _menu.setHidden(true);
        _inGame = true;
    });

    QObject::connect(_menu.getStartButton2(), &QPushButton::clicked,
                     this, [&] (){
        _levelStarter.play();
        _gameProxy.initializeGame(2);
        _gameWidget.setHidden(false);
        _menu.setHidden(true);
        _inGame = true;
    });

    QObject::connect(_gameWidget.getGameScene(), &GameScene::helpRequested,
                     this, [&](){
        setFocus();
        showHelp();
    });

    QObject::connect(_gameWidget.getGameScene(), &GameScene::pauseRequested,
                     this, [&](){
        setFocus();
        showPause();
    });
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_H)
    {
        if (_help.isHidden())
            showHelp();
        else
            hideHelp();
    }
//TODO: podesi indikator za pauzu
//    else if(event->key() == Qt::Key_P)
//        if (_pause.isHidden()) showPause(); else hidePause();
}
