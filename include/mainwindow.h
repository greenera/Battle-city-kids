#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>
#include "include/menu.h"
#include "include/gameproxy.h"
#include "include/help.h"
#include <QSoundEffect>
#include "include/pause.h"

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
    bool _inGame;

    Help *_help;
    Pause* _pause;
    Menu *_menu;
    GameWidget *_gameWidget;
    GameProxy *_gameWrapper;

    Ui::MainWindow *_ui;
    QSoundEffect _testEfekat;

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
