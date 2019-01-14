#include "include/npc.h"

Npc::Npc(qreal x, qreal y, int id)
   : Tank(id)
{
    _activeIcon = "Down";

    _shootTimer.setInterval(2000);
    QObject::connect(&_shootTimer, &QTimer::timeout,
                     this, &Tank::shoot);
    _shootTimer.start();

    _x = x;
    _y = y;
}

Npc::~Npc()
{

}

//Npc::Npc(const Npc &other) = default;


void Npc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Tank::paint(painter, option, widget);
}
