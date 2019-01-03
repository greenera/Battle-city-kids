#ifndef PLAYER_H
#define PLAYER_H

#include <include/tank.h>

class Player : public Tank
{
public:
    Player();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLAYER_H
