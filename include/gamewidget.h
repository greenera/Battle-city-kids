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

public slots:
    void printMap(const QVector<QVector<int>> matrixOfLevel) const;

private:
    const int _sizeOfScene = 25 * 13; //!< 25 stands for number of rects, and 13 for size of every rect
    QGraphicsScene* _scene;
    Ui::GameWidget *_ui;
};

#endif // GAMEWIDGET_H
