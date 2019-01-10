#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>
#include "include/menu.h"
#include "include/boost.h"
#include "include/gamescene.h"
#include "include/gameproxy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //deleted copy constructor and operator '='
    MainWindow(const MainWindow&) = delete;
    MainWindow& operator = (const MainWindow&) = delete;

private slots:
    /**
     * @brief newGame create new game
     */
    void restartGame();

    /**
     * @brief pauseGame pause game
     */
    void pauseGame();

    /**
     * @brief exitLevel exit to main menu
     */
    void exitLevel();

    /**
     * @brief showHelp show in-game help
     */
    void showHelp();

    /**
     * @brief hideHelp hide in-game help
     */
    void hideHelp();

private:

    void connectSlotsAndSignals();

    Menu *_menu;
    GameWidget *_gameWidget;
    GameProxy *_gameWrapper;

    Ui::MainWindow *_ui;
};

#endif // MAINWINDOW_H
