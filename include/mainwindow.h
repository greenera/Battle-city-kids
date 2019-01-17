#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>
#include "include/menu.h"
#include "include/gameproxy.h"
#include "include/help.h"
#include <QSoundEffect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MainWindow(const MainWindow&) = delete;
    MainWindow& operator = (const MainWindow&) = delete;

private slots:
    /**
     * @brief showHelp show in-game help
     */
    void showHelp();

    /**
     * @brief hideHelp hide in-game help
     */
    void hideHelp();

    /**
     * @brief showPause show pause screen
     */
    void showPause();

    /**
     * @brief hidePause hide pause screen
     */
    void hidePause();

private:
    /*!
     * \brief connect Connect signals and slots
     */
    void connect();

    bool _inGame; //TODO: move to gameWraper, and make function for taking this info
    Help _help; //!< widget that shows help
    Menu _menu; //!< widget with menu
    GameWidget _gameWidget; //!< widget with game
    GameProxy _gameProxy; //!< proxy for widget game, separate logic from gameWidget
    QSoundEffect _levelStarter; //TODO: prebaci u gameScene pa tamo pozivaj pri pocetku svakog nivoa
    Ui::MainWindow *_ui;

protected:
    /*!
     * \brief keyPressEvent
     * \param event
     * \details only purpose for showing help page.
     * Should be invoked in child's function too.
     * Done by signal.
     */
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
