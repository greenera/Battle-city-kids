#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();

private:
    const int _sizeOfScene = 26 * 15; //!< 26 stands for number of rects, and 15 for size of every rect
    Ui::GameWidget *_ui;
};

#endif // GAMEWIDGET_H
