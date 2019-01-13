#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include <QFile>
#include <fstream>
#include <QVector>
#include <QString>
#include "include/boost.h"
#include "include/tank.h"
#include "include/npc.h"
#include "include/block.h"
#include "include/player.h"
#include <QGraphicsView>

#define NUM_OF_LEVELS 3

/*!
 * \brief Game::Game
 * \details This is the class with information about current game.
 * Purpose: always knows which level is active and display it to mainWindow.
 */
class Game : public QGraphicsScene
{
    Q_OBJECT

public:
    Game(QGraphicsView* parrent = nullptr);
    void initializeLevel(int level);
    void abort();


public slots:
    void printMap(const QVector<QVector<int>> matrixOfLevel);

signals:
    void endOfLevel(double score);

private:
    /*!
     * \brief loadLevel opens file for activeLevel
     * and fill the matrixOfLevel acording to that file.
         TODO: Generate vector of npcs .
     *
     * \details Function should be called at the begining of every level
     * which is when npcs vector become empty. The file should have
     * the number of every type of npc that will be in that level. Sum
     * of all numbers should be equal to 20
     */
    void loadLevel(int levelNum);

    /*!
     * \brief update the scene and view
     */
    void update();

    /*!
     * \brief countBonusScore
     * \param typeOfKilledEnemy in range [1,4]
     * \details calculate bonusScore, based on what type of enemy
     * is killed. Be sure to divide this number with minutes
     * of level leasting before signal it to basic score.
     */
    void countBonusScore(int typeOfKilledEnemy);
    long _bonusScore;

    QVector<Npc> _npcs; //!< live npcs
    int numOfEnemyByType[4];

    Player* _players[2]; //!< live players (max 2)
    QVector<Boost> _powerups;

    QVector<QVector<int>> matrixOfLevel;

    QTimer _levelTicker;
    const int _sizeOfScene = 25 * 26; //!< 26 stands for number of rects, and 25 for size of every rect

    QGraphicsView *_parrent;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAME_H
