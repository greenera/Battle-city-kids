#include "boost.h"

Boost::Boost()
{
    pos_x = QRandomGenerator::global()->bounded(26);
    pos_x = QRandomGenerator::global()->bounded(26);
    _powerup = BoostType(rand()%5);
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

int Boost::getX() const{
    return pos_x;
}

void Boost::setY(const int& value){
    pos_y = value;
}

int Boost::getY() const{
    return pos_y;
}

