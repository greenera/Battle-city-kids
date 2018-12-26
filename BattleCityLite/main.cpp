// Starter of Battle city lite game which is
// inspired by the game for "sega" with the same name.

#include <QApplication>
#include <QtWidgets>
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
    w.show();

    return a.exec();
}
