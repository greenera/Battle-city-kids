#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QPainter>

class Bullet: public QGraphicsItem
{
public:

    // Constructor
    Bullet(qreal x, qreal y, int parent, qreal speed, int direction);
    //~Bullet();
   // Bullet(const Bullet& other);

    // Overrides from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    QPainterPath shape() const override;

    // Getters
    qreal getX() const;
    qreal getY() const;
    void setX(const qreal& x);
    void setY(const qreal& y);

    void moveBullet();
    void coliding();
    bool _moving = true;

private:
    int size = 10;
    int _parent; // Player or npc
    qreal _speed;
    int _direction;
    qreal pos_x;
    qreal pos_y;
    QPixmap _texture = QPixmap(":/blocks/bullet.png");
};

#endif // BULLET_H
