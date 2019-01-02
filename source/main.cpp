// Starter of Battle city lite game which is
// inspired by the game for "sega" with the same name.

#include <QApplication>
#include <QtWidgets>
#include "include/menu.h"
#include "include/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setFixedSize(900, 650);

    w.show();

    return a.exec();
}
