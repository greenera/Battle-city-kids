#ifndef BOOST_H
#define BOOST_H

#include <QGraphicsObject>
#include <QRandomGenerator>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QGraphicsObject>

class Boost: public QGraphicsItem
{
public:
    /*!
     * \brief BoostType enum
     * defines types of powerups
     !*/

    enum BoostType{
        gun_boost,
        fenix_shield,
        tank_shield,
        freeze,
        bomb
    };
    /**
     * @brief Boost consturctor of a random powerup at a random place
     */
    Boost();

    /**
     * @brief Boost consturctor of a random powerup at (x, y) position
     * @param x
     * @param y
     */
    Boost(qreal x, qreal y);

    Boost(const Boost& other) = delete;

    ~Boost() override = default;

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QPainterPath shape() const override;


    /**
     * @brief setTexture assigns value to _texture variable
     * @param t
     */
    void setTexture(const BoostType& t);

    /**
     * @brief generateRandomPowerup generates random powerup
     */
    void generateRandomPowerup();

    /*!
     * \brief setters and getters...
     */

    void setPowerup(const BoostType& value);
    BoostType getPowerup() const;

    void setX(const int& value);
    qreal getX() const;

    void setY(const int& value);
    qreal getY() const;

protected:

    /*!
     * \brief pos_x horisontal position
     * \brief pos_y vertical position
     */
    qreal _size = 50;
    qreal pos_x, pos_y;

    BoostType _powerup = BoostType::fenix_shield;

    QPixmap _texture;
};

#endif // BOOST_H
