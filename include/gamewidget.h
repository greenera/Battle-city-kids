#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include "include/boost.h"
#include "include/game.h"
#include "include/block.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    void initializeGame();
    Game *getGameScene();

public slots:
    void printMap(const QVector<QVector<int>> matrixOfLevel) const;

private:
    Game *_scene;
    Ui::GameWidget *_ui;
};

#endif // GAMEWIDGET_H
