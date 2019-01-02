// Starter of Battle city lite game which is
// inspired by the game for "sega" with the same name.

#include "include/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
