#include "include/bullet.h"


Bullet::Bullet(int x, int y, int parent, qreal speed, int direction)
    :_parent(parent), _speed(speed), _direction(direction), pos_x(x), pos_y(y)
    {
    }
Bullet::~Bullet() = default;

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
int Bullet::getX() const
{
    return pos_x;
}
int Bullet::getY() const
{
    return pos_y;
}

void Bullet::setX(const int& x) {
    pos_x = x;
}
void Bullet::setY(const int& y) {
    pos_y = y;
}

void Bullet::moveBullet()
{
    if (_moving) {
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
}

void Bullet::coliding() {
    QList<QGraphicsItem*> list = collidingItems();
}
