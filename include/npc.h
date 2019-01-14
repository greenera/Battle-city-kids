#ifndef NPC_H
#define NPC_H
#include "include/tank.h"
#include <QTimer>

class Npc : public Tank
{
public:
    //TODO Ivana: implementiraj sveto trojstvo
    Npc(bool isBlinking, int iq, int id);
    ~Npc();
    Npc(const Npc& other);

signals:
    void constructBullet(/*ovde dodaj sve parametre koje treba bullet da ima*/);

public slots:
    void onCollision();

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int _iq;
    bool _blinking;
    QTimer _shootTimer;
};

#endif // NPC_H
