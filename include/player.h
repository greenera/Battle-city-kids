#ifndef PLAYER_H
#define PLAYER_H

#include <include/tank.h>

class Player : public Tank
{
public:
    Player(int id);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif // PLAYER_H
