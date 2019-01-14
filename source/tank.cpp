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

int Tank::getDirection()
{
    if (!_activeIcon.compare("Up"))
        return 1;
    if (!_activeIcon.compare("Down"))
        return 3;
    if(!_activeIcon.compare("Right"))
        return 2;

    return 4;
}


//TODO: treba setovati pokazivac na funkciju na
//horizontal ili verical zavisi od fje do fje
void Tank::setUp(bool t)
{
    _activeIcon = "Up";     //!< this is enough to happen only one
    _moving = t;              //!< this indicates that tank should moving
    adjustPosition();
    move();
}

void Tank::setDown(bool t)
{
    _activeIcon = "Down";
    _moving = t;
    adjustPosition();
    move();
}

void Tank::setRight(bool t)
{
    _activeIcon = "Right";
    _moving = t;
    adjustPosition();
    move();
}

void Tank::setLeft(bool t)
{
    _activeIcon = "Left";
    _moving = t;
    adjustPosition();
    move();
}

//void Tank::move()
//{
//    if(!_moving)
//        return;

//    //fmove(); TODO: napravi pokazivac na funkciju
//}

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

void Tank::move() {
    int direction = getDirection();
    switch (direction) {
        case 1:
            _y -= _speed;
            break;
        case 2:
            _x += _speed;
            break;
        case 3:
            _y += _speed;
            break;
        case 4:
            _x -= _speed;
            break;
    }

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
