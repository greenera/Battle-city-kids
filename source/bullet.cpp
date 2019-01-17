#include "include/bullet.h"


Bullet::Bullet(int x, int y, int parent, qreal speed, int direction)
    : _parent(parent),
      _speed(speed),
      _direction(direction),
      _x(x),
      _y(y)
{
    _speed = 16;
}


void Bullet::moveBullet()
{

    switch (_direction) {
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

    if(_x > 600 || _x < 0 || _y > 600 || _y < 0)
       // delete this;
    setPos(_x, _y);
}

void Bullet::coliding()
{
    QList<QGraphicsItem*> list = collidingItems();
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, _size, _size);
}

void Bullet::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture.scaledToHeight(_size)));
    painter->drawRect(0, 0, _size, _size);
}
