#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include "include/boost.h"
#include "include/gamescene.h"
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
    GameScene *getGameScene();

public slots:
    void printMap(const QVector<QVector<int>> matrixOfLevel) const;

private:
    GameScene *_scene;
    Ui::GameWidget *_ui;
};

#endif // GAMEWIDGET_H
