#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "include/gamewidget.h"
#include "include/gamescene.h"


class GameProxy : public QObject
{
    Q_OBJECT

public:
    GameProxy(GameWidget* gameWidget);

    /**
     * @brief initializeGame function for game initialization
     */
    void initializeGame(int numOfPlayers);

signals:
    /**
     * @brief gameOver signal end of current game
     */
    void gameOver();

private:
    /**
     * @brief changeLifes
     */
    void changeLifes();
    /**
     * @brief exitToMainMenu return to main menu
     */
    void exitToMainMenu();

    /*!
     * \brief updateScore
     * \details should be caled after end of every level,
     * and after death.
     */
    void updateScore(double score);
    void saveScore();

public slots:
    void onEndOfLevel(double bonus);

private:
    int _activeLevel;
    int _numOfLives;
    int _playersNum;
    double _score;

    GameWidget *_gameWidget;
};

#endif // GAMEWRAPPER_H
