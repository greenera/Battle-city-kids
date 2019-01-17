#include "include/block.h"

Block::Block(int x, int y, bool collidable, Material m, QString texture)
    : _collidable(collidable),
      _material(m),
      _texture(QPixmap(texture))
{
    setPos(x, y);
}

Block::Block(int x, int y, QString texture)
    : _size(50),
      _collidable(true),
      _texture(QPixmap(texture))
{
    setPos(x, y);
}

QRectF Block::boundingRect() const
{
    return QRectF(0, 0, _size, _size);
}

void Block::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *,
                  QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture.scaledToHeight(_size)));
    painter->drawRect(0, 0, _size, _size);
}
