#include "include/boost.h"
#include <QDebug>
#include <iostream>

Boost::Boost()
{
    qreal _y = QRandomGenerator::global()->bounded(25*26);
    qreal _x = QRandomGenerator::global()->bounded(25*26);
    srand(time(nullptr));
    _powerup = BoostType(rand()%5);
    Boost::setTexture(_powerup);
    setPos(_x, _y);
}

void Boost::setTexture(const BoostType& t)
{
    if(t == Boost::BoostType::bomb){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Grenade.png");
    } else if(t == Boost::BoostType::tank_shield){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Tank.png");
    }else if(t == Boost::BoostType::freeze){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Timer.png");
    }else if(t == Boost::BoostType::gun_boost){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Star.png");
    }else if(t == Boost::BoostType::phoenix_shield){
        _texture = QPixmap(":/boosts/Battle_City_Powerup_Helmet.png");
    }
}

Boost::BoostType Boost::getPowerup() const
{
    return _powerup;
}

QRectF Boost::boundingRect() const
{
    return QRectF(0, 0, _size, _size);
}

void Boost::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture.scaledToHeight(_size)));
    painter->drawRect(0, 0, _size, _size);
}
