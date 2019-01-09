#include "include/game.h"
#include <QFile>
/**
 * @brief Game::Game
 * @param parrent
 * \details Scena koja predstavlja igru. Tu se regulise igra u okviru nivoa.
 * Trebalo bi preimenovati je u levelScene, takodje prebaciti sve sto ima veze sa scenom ovde.
 */


Game::Game(QWidget* parrent)
    : QGraphicsScene(parrent),
    matrixOfLevel(26, QVector<int>(26))
{
    this->setSceneRect(0, 0, _sizeOfScene, _sizeOfScene);
    setBackgroundBrush(QColor(0, 0, 0));

    initializeGame();

//    QObject::connect(_updateTimer, &QTimer::timeout, this, &Game::update);
}


void Game::initializeGame()
{
    loadLevel(2);

    //createNpcs(); TODO Ivana: implementiraj
}

// Loads level from file
void Game::loadLevel(int levelNum)
{
    QString path = QStringLiteral(":/levels/%1.txt").arg(levelNum);
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    char c;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            file.read(&c,sizeof(char));
            if(c == '\n') {
                j--;
                continue;
            }
            matrixOfLevel[i][j] = c - '0'; // Write data into matrix
        }
    }
    file.close(); // Close the file
}
