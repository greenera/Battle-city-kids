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

int Tank::getSmer()
{
    if (!_activeIcon.compare("Up"))
        return 1;
    if (!_activeIcon.compare("Down"))
        return 2;
    if(!_activeIcon.compare("Right"))
        return 3;

    return 4;
}


//TODO: treba setovati pokazivac na funkciju na
//horizontal ili verical zavisi od fje do fje
void Tank::setUp(bool t)
{
    _activeIcon = "Up";     //!< this is enough to happen only one
    _moving = t;              //!< this indicates that tank should moving
    _speed = _speed < 0 ? _speed : -_speed;
}

void Tank::setDown(bool t)
{
    _activeIcon = "Down";
    _moving = t;
    _speed = _speed < 0 ? -_speed : _speed;
}

void Tank::setRight(bool t)
{
    _activeIcon = "Right";
    _moving = t;
    _speed = _speed < 0 ? -_speed : _speed;
}

void Tank::setLeft(bool t)
{
    _activeIcon = "Left";
    _moving = t;
    _speed = _speed < 0 ? _speed : -_speed;
}

void Tank::move()
{
    if(!_moving)
        return;

    //fmove(); TODO: napravi pokazivac na funkciju
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
    QRectF source(0.0, 0.0, _size, _size);
    QRectF target(_x, _y, _size, _size);
    painter->drawPixmap(target, _icons[_activeIcon], source);
//    painter->setBrush(QBrush(_icons[_activeIcon].scaledToHeight(_size)));
//    painter->drawRect(_x, _y, _size, _size);
}

void Tank::vertical()
{
    _y += _speed;
}

void Tank::horizontal()
{
    _x += _speed;
}
