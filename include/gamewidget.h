#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "include/gamescene.h"

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    void initializeLevel(int level);
    GameScene *getGameScene();
    void setLifeInformation(int num);

    /*!
     * \brief abort, deletes everything when game is over
     */
    void abort();

signals:
    void endOfLevel(double forward);

private slots:
    void onEndOfLevel(double forward);

private:
    void setLevelName(int level);
    void resetTimeLabel();
    void setTimeLabel();

    void initSmallTankText();

    GameScene *_scene;
    Ui::GameWidget *_ui;
    QTimer _refreshingLabel;
    int _minutes, _sec;

    QPixmap _small_tenk;
};

#endif // GAMEWIDGET_H
