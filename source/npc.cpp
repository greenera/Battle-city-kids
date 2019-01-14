#include "include/npc.h"

Npc::Npc(bool isBlinking, int iq, int id)
    : _blinking(isBlinking), Tank(id)
{
    _activeIcon = "Down";
    _shootTimer.setInterval(2000);
    QObject::connect(&_shootTimer, &QTimer::timeout,
                         this, &Tank::shoot);
    _shootTimer.start();
}

Npc::~Npc()
{

}

void Npc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Tank::paint(painter, option, widget);

    if(_blinking)
    {
        //TODO: namesti miganje
    }

    //TODO: dodaj stit ako ga je sakupio
}
