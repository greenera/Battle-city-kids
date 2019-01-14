#ifndef NPC_H
#define NPC_H
#include <QTimer>
#include "include/tank.h"
#include <QTimer>

class Npc : public Tank
{
public:
    //TODO Ivana: implementiraj sveto trojstvo
    Npc(qreal x, qreal y, int id);
    ~Npc();
    Npc(const Npc& other);

public slots:
    void onCollision();

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QTimer _shootTimer;
};

#endif // NPC_H
