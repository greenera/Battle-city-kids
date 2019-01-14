#include "include/tank.h"
#define SPEED_LIMIT 2

#include <QPainter>

Tank::Tank(int id)
    :grid(27)
{
    for (int i = 0; i < 27; i++)
        grid[i] = i*25;
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

void Tank::setUp(bool t)
{
    _movingUp = t;
    if (t)
    {
        _activeIcon = "Up";  //!< this is enough to happen only one
        _movingDown = _movingLeft = _movingRight = false;
    }
    adjustPosition();
}

void Tank::setDown(bool t)
{
    _movingDown = t;
    if (t)
    {
        _activeIcon = "Down";
        _movingUp = _movingLeft = _movingRight = false;
    }
    adjustPosition();
}

void Tank::setRight(bool t)
{
    _movingRight = t;
    if (t)
    {
        _activeIcon = "Right";
        _movingUp = _movingLeft = _movingDown = false;
    }
    adjustPosition();
}

void Tank::setLeft(bool t)
{
    _movingLeft = t;
    if (t)
    {
        _activeIcon = "Left";
        _movingUp = _movingDown = _movingRight = false;
    }
    adjustPosition();
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

int Tank::getDirection()
{
    if (!_activeIcon.compare("Up"))
        return 1;
    if (!_activeIcon.compare("Down"))
        return 3;
    if (!_activeIcon.compare("Right"))
        return 2;

    return 4;
}

void Tank::move()
{
    if (!_moving)
        return;

    if (_movingUp)
        _y -= _speed;
    else if (_movingRight)
        _x += _speed;
    else if (_movingDown)
        _y += _speed;
    else if (_movingLeft)
        _x -= _speed;
}

void Tank::setMoving(bool x)
{
    _moving = x;
}

void Tank::adjustPosition()
{
    if (_x < 0)
        _x = 0;
    else if (_y < 0)
        _y = 0;
    else if (_x > 600)
        _x = 600;
    else if (_y > 600)
        _y = 600;

    int i = 0;
    if (getDirection() == 1 || getDirection() == 3) {
        for (i = 0; i < 27; i++) {
            if (_x < grid[i])
                break;
        }
        _x = (_x - grid[i-1]) < (grid[i] - _x) ? grid[i-1] : grid[i];
    }
    else {
        for (i = 0; i < 27; i++) {
            if (_y < grid[i])
                break;
        }
        _y = (_y - grid[i-1]) < (grid[i] - _y) ? grid[i-1] : grid[i];
    }
}
