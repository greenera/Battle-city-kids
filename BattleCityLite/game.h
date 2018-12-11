#ifndef GAME_H
#define GAME_H

#include <npc.h>
#include <QFile>

#define NUMOFLEVELS 1

/*!
 * \brief Game::Game
 * \details This is the class with information about current game.
 * Purpose: always knows which level is active and display it to mainWindow.
 */
class Game
{
public:
    Game();

    //TODO: consider making class for adding new  levels
    QFile levelsPath[NUMOFLEVELS];
    int activeLevel;
    //MatricaNivoa matrixOfLevel[13][13]; TODO Nenad: napraviti klasu

    /*!
     * \brief openLevel opens file from levelsPath of activeLevel
     * and fill the matrixOfLevel acording to that file. Also, generate
     * vector of npcs acording to that informations.
     * \details Function should be called at the begining of every level
     * which is when npcs vector become empty. The file should have
     * the number of every type of npc that will be in that level. Sum
     * of all numbers should be equal to 20
     */
    void openLevel();

    //QVector<Npc> npcs; TODO Ivana: dodaj kada implementiras npc

    //Player players[2]; //TODO Ivana: napravi klasu
    int numOfLifes;

    //QVector<Boost> boosts; //TODO Matija: napravi klasu

};

#endif // GAME_H
