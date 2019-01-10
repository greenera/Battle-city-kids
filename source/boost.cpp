#include "include/boost.h"
#include <QDebug>
#include <iostream>

Boost::Boost()
{
    pos_x = QRandomGenerator::global()->bounded(26);
    pos_x = QRandomGenerator::global()->bounded(26);
    Boost::generateRandomPowerup();
    Boost::setTexture(_powerup);
}

Boost::Boost(qreal x, qreal y)
    : pos_x(x), pos_y(y){
    Boost::generateRandomPowerup();
    Boost::setTexture(_powerup);
}

QRectF Boost::boundingRect() const{
    return QRectF(pos_x, pos_y, _size, _size);
}
void Boost::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture.scaledToHeight(_size)));
    painter->drawRect(pos_x, pos_y, _size, _size);

}
QPainterPath Boost::shape() const
{
    QPainterPath path;
    path.addRect(pos_x, pos_y, _size, _size);
    return path;
}

void Boost::generateRandomPowerup(){
    srand(time(NULL));
    _powerup = BoostType(rand()%5);
}

void Boost::setTexture(const BoostType& t){
    if(t == Boost::BoostType::bomb){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Grenade.png");
    } else if(t == Boost::BoostType::tank_shield){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Tank.png");
    }else if(t == Boost::BoostType::freeze){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Timer.png");
    }else if(t == Boost::BoostType::gun_boost){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Star.png");
    }else if(t == Boost::BoostType::fenix_shield){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Helmet.png");
    }
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


