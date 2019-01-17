#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QPainter>
#include <QGraphicsObject>

/*!
 * \brief The Block class, represents the
 * static object on scene.
 */
class Block: public QGraphicsObject
{
public:
    /*!
     * \brief The Material enum
     * Defines type of obstacle.
     */
    enum Material {
        brick,
        stone,
        water,
        bush,
        base
    };

    /*!
     * \brief Block constructor
     * \param x
     * \param y
     * \param collidable
     * \param m
     * \param texture
     */
    Block(int x, int y, bool collidable, Material m, QString texture);

    /*!
     * \brief Block constructor used for creating phoenix
     * \param x
     * \param y
     * \param texture
     */
    Block(int x, int y, QString texture);

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;

private:
    int _size = 25; //!<-- size of all blocks except phoenix
    bool _collidable; //!<-- should stop the tank
    //TODO: dodaj treba li da zaustavi bullet
    Material _material; //!<-- tells the behavior of block on colision
    QPixmap _texture; //!<-- for painting
};

#endif // BLOCK_H
