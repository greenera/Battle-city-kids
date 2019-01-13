#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>
#include "include/menu.h"
#include "include/gamewrapper.h"
#include "include/help.h"

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

private:
    bool _inGame;

    Help *_help;
    Menu *_menu;
    GameWidget *_gameWidget;
    GameWrapper *_gameWrapper;

    Ui::MainWindow *_ui;

protected:
    /*!
     * \brief keyPressEvent
     * \param event
     * \details only purpose for showing help page.
     * Should be invoked in child's function too.
     */
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
