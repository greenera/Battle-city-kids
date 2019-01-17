#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsObject>
#include <QPainter>

class Bullet: public QGraphicsObject
{
    Q_OBJECT

public:

    /*!
     * \brief Bullet constructor
     * \param x starting x coordinate
     * \param y starting y coordinate
     * \param parent
     * \param speed
     * \param direction
     */
    Bullet(int x, int y, int parent, qreal speed, int direction);

    Bullet(const Bullet& other) = default;

    void moveBullet();
    void coliding();

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
private:
    int _size = 10;
    int _parent; // Player or npc
    qreal _speed;
    int _direction;
    int _x;
    int _y;
    QPixmap _texture = QPixmap(":/blocks/bullet.png");
};

#endif // BULLET_H
