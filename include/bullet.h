#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QPainter>

class Bullet: public QGraphicsItem
{
public:

    // Constructor
    Bullet(int x, int y, int parent, qreal speed, int direction);
    ~Bullet() override;
    Bullet(const Bullet& other) = delete;

    // Overrides from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    QPainterPath shape() const override;

    // Getters
    int getX() const;
    int getY() const;
    void setX(const int& x);
    void setY(const int& y);

    void moveBullet();
    void coliding();
    bool _moving = true;

private:
    int size = 10;
    int _parent; // Player or npc
    qreal _speed;
    int _direction;
    int pos_x;
    int pos_y;
    QPixmap _texture = QPixmap(":/blocks/bullet.png");
};

#endif // BULLET_H
