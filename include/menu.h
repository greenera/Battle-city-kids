#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QFile>
#include <QPainter>
#include <ui_menu.h>
#include <QKeyEvent>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    //~Menu();

    //deleted copy constructor and operator '='
    Menu(const Menu&) = delete;
    Menu& operator = (const Menu&) = delete;

    QPushButton *getStartButton();
    QPushButton *getStartButton2();

    void keyPressEvent(QKeyEvent* event) override;

private slots:
    /**
     * @brief startGame begins new game
     */
    void startGame();

    /**
     * @brief exitProgram exits program
     */
    void exitProgram();



private:
    Ui::Menu *_ui;

    /**
     * @brief connectSlotsAndSignals enables program function to catch actions
     */
    void connectSlotsAndSignals();
    QString loadScore();
};

#endif // MENU_H
