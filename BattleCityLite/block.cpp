#include "block.h"

Block::Block(qreal x, qreal y, bool collidable, Material m, QString texture)
    : pos_x(x), pos_y(y), _collidable(collidable), _m(m), _texture(texture)
    {
        setPos(x, y);
    }

QRectF Block::boundingRect() const
    {
        return QRectF(pos_x, pos_y, size, size);
    }
void Block::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture));
    painter->drawRect(pos_x, pos_y, size, size);
}

QPainterPath Block::shape() const
{

    QPainterPath path;
    path.addRect(pos_x, pos_y, size, size);
    return path;
}

qreal Block::getX()
{
    return pos_x;
}
qreal Block::getY()
{
    return  pos_y;
}

