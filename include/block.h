#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QPainter>
#include <QGraphicsObject>

// Class for obstacles

class Block: public QGraphicsObject
{
public:
    // Defines type of obstacle
    enum Material {
        brick,
        stone,
        water,
        bush
    };

    Block(qreal x, qreal y, bool collidable, Material m, QString texture);
    //~Block();
    Block(const Block& other) = delete;

    // Overrides from QGraphicsObject
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    QPainterPath shape() const override;

    qreal getX();
    qreal getY();

private:
    int size = 20;
    qreal pos_x;
    qreal pos_y;
    bool _collidable;
    Material _m;
    QPixmap _texture;
};

#endif // BLOCK_H
