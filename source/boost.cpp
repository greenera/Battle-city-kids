#include "include/boost.h"
#include <QDebug>

Boost::Boost()
    :_texture(":/boosts/Battle_City_Powerup_Grenade.png")
{
    pos_x = QRandomGenerator::global()->bounded(26);
    pos_x = QRandomGenerator::global()->bounded(26);
    _powerup = BoostType(rand()%5);
}

Boost::Boost(qreal x, qreal y)
    : pos_x(x), pos_y(y), _texture(":/boosts/Battle_City_Powerup_Grenade.png"){}

QRectF Boost::boundingRect() const{
    return QRectF(pos_x, pos_y, _size, _size);
}

void Boost::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::white);
    painter->setBrush(QBrush(_texture.scaledToHeight(_size)));
    painter->drawRect(pos_x, pos_y, _size, _size);

}

QPainterPath Boost::shape() const
{

    QPainterPath path;
    path.addRect(pos_x, pos_y, _size, _size);
    return path;
}

void Boost::setPowerup(const BoostType& value){
    _powerup = value;
}

Boost::BoostType Boost::getPowerup() const{
    return _powerup;
}

void Boost::setX(const int& value){
    pos_x = value;
}

qreal Boost::getX() const{
    return pos_x;
}

void Boost::setY(const int& value){
    pos_y = value;
}

qreal Boost::getY() const{
    return pos_y;
}


