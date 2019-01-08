#include "include/tank.h"
#define SPEED_LIMIT 2

#include <QPainter>

Tank::Tank(int id)
{
    //uploading icons
    QString iconName(":/tanks/");
    if(id > 2)
        iconName = iconName.append("npc/enemy").append(QString::number(id - 2));
    else
        iconName = iconName.append("player/player").append(QString::number(id));

    //TODO dogovor: da li da ostane ovako ili da se radi rotacija?
    _icons.insert("Up", QPixmap(iconName + "Up.png"));
    _icons.insert("Down", QPixmap(iconName + "Down.png"));
    _icons.insert("Right", QPixmap(iconName + "Right.png"));
    _icons.insert("Left", QPixmap(iconName + "Left.png"));
}

Tank::~Tank()
{

}

Tank::Tank(const Tank &other)
{


}

void Tank::onShot()
{
    if(!_resistent)
        delete this; //NOTE: check if this work
    --_resistent;
}

void Tank::setSpeed(qreal increasing)
{
    _speed = _speed + increasing > SPEED_LIMIT ? SPEED_LIMIT : _speed + increasing;
}

Tank::Weapon Tank::getWeapon()
{
    return _weapon;
}

void Tank::setWeapon(const Tank::Weapon &newWeapon)
{
    _weapon = newWeapon;
}

QRectF Tank::boundingRect() const
{
    return QRectF(_x, _y, _size, _size);
}

void Tank::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_icons[_activeIcon].scaledToHeight(_size)));
    painter->drawRect(_x, _y, _size, _size);
}

void Tank::onUp()
{
    _activeIcon = "Up";
    //NOTE: izabrati jedno od ova dva u zavisnosti da li se negde
    //drugde proverava da tenk ne izleti sa scene
    // _y -= _speed;
    _y = _y - _speed < 0 ? 0 : _y - _speed;
}

void Tank::onDown()
{
    _activeIcon = "Down";
    //NOTE: isto kao za onUp
    // _y += _speed;
    _y = _y + _speed > 600 ? 600 : _y + _speed;
}

void Tank::onLeft()
{
    _activeIcon = "Left";
    _x -= _speed;
}

void Tank::onRight()
{
    _activeIcon = "Right";
    _x += _speed;
}
