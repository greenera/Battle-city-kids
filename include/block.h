#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>

// Class for obstacles

class Block: public QGraphicsItem
{
public:
    // Defines type of obstacle
    enum Material {
        brick,
        stone,
        water,
        bush,
        base
    };

    Block(int x, int y, bool collidable, Material m, QString texture);

    // Constructor used for creating phoenix
    Block(int x, int y, QString texture);
    //~Block();
    Block(const Block& other) = delete;

    // Overrides from QGraphicsObject
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    QPainterPath shape() const override;

    int getX();
    int getY();

private:
    int size = 25;
    int pos_x;
    int pos_y;
    bool _collidable;
    Material _m;
    QPixmap _texture;
};

#endif // BLOCK_H
