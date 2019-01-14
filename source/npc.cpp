#include "include/npc.h"

Npc::Npc(qreal x, qreal y, int id)
   : Tank(id+2)
{
    _activeIcon = "Down";

    _shootTimer.setInterval(2000);
    QObject::connect(&_shootTimer, &QTimer::timeout,
                     this, &Tank::shoot);
    _shootTimer.start();

    _x = x;
    _y = y;
    if (id > 4)
        _speed = 4;
    if (id == 6)
        _resistent = 4;
}

Npc::~Npc() = default;

//Npc::Npc(const Npc &other) = default;


void Npc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Tank::paint(painter, option, widget);
}
