#include "include/game.h"
#include <QFile>

Game::Game()
    : matrixOfLevel(26, QVector<int>(26))
{

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
            matrixOfLevel[i][j] = c - '0'; // Read data into matrix
        }
    }
    file.close(); // Close the file
}
