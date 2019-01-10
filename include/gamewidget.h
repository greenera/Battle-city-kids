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
    explicit GameWidget(QWidget *parent = nullptr, QGraphicsScene *scene = nullptr);
    ~GameWidget();

public slots:


private:
    QGraphicsScene *_scene;
    Ui::GameWidget *_ui;
};

#endif // GAMEWIDGET_H
