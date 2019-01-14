#include "include/bullet.h"


Bullet::Bullet(qreal x, qreal y, int parent, qreal speed, int direction)
    :pos_x(x), pos_y(y), _parent(parent), _speed(speed), _direction(direction)
    {
    }
//Bullet::Bullet(const Bullet& other)

QRectF Bullet::boundingRect() const
{
    return QRectF(pos_x, pos_y, size, size);
}

void Bullet::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture.scaledToHeight(size)));
    painter->drawRect(pos_x, pos_y, size, size);
}

QPainterPath Bullet::shape() const
{

    QPainterPath path;
    path.addRect(pos_x, pos_y, size, size);
    return path;
}

// Getters
qreal Bullet::getX() const
{
    return pos_x;
}
qreal Bullet::getY() const
{
    return pos_y;
}

void Bullet::moveBullet()
{
    switch (_direction) {
        case 1:
            pos_y -= _speed;
            break;
        case 2:
            pos_x += _speed;
            break;
        case 3:
            pos_y += _speed;
            break;
        case 4:
            pos_x -= _speed;
            break;
    }
}
