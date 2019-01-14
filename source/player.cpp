#include "include/player.h"
#include <QPainter>

#include <QDebug>

#define START_POSITION_X 75
#define DISTANCE 150
#define START_POSITION_Y 600

Player::Player(int id)
    : Tank(id)
{
    _x = START_POSITION_X + id * DISTANCE;
    _y = START_POSITION_Y;

    _activeIcon = "Up";

    //FOR TEST
    _speed = 2;
    _resistent = 0;
    _weapon = Weapon::gun;
    _isManual = true;
    //END OF TEST
}

void Player::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Tank::paint(painter, option, widget);

    //TODO: dodaj oznaku da ima neki boost
}
