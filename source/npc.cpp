#include "include/npc.h"
#include <QDebug>
Npc::Npc(qreal x, qreal y, int id)
   : Tank(id+2)
{
    _activeIcon = "Down";
    _npcDirection =0;
    _shootTimer.setInterval(2000);
    QObject::connect(&_shootTimer, &QTimer::timeout,
                     this, [&](){shootingEnabled = true;});
    _shootTimer.start();

    _x = x;
    _y = y;
    if (id > 4)
        _speed = 4;
    if (id == 6)
        _resistent = 4;
}

void Npc::colisionDetection()
{
    srand(time(NULL));
    int r = rand()%4;
    QList<QGraphicsItem*> list = collidingItems();
    if (list.length() > 0)
    {
        reMoving();
        _npcDirection = r;
    }
    if (_x < 0 || _x > 600 || _y < 0 || _y > 600)
        _npcDirection = r;
}

Npc::~Npc() = default;

//Npc::Npc(const Npc &other) = default;


void Npc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Tank::paint(painter, option, widget);
}
