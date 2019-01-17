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
     * defines types of powerup
     !*/
    enum BoostType{
        gun_boost,
        phoenix_shield,
        tank_shield,
        freeze,
        bomb,
        star
    };

    /**
     * @brief Boost consturctor of a random powerup at a random place
     */
    Boost();
    ~Boost() override = default;

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    /*!
     * \brief getPowerup
     * \return type of powerup
     * TODO: razmotri da se vraca samo pokazivac na
     * fju koja se poziva ako dodje do kolizije sa tim bustom
     */
    BoostType getPowerup() const;

private:
    qreal _size = 50; //!<-- size of powerup
    BoostType _powerup = BoostType::phoenix_shield; //!<-- default powerup
    QPixmap _texture; //!<-- for painting

    /**
     * @brief setTexture assigns value to _texture variable
     * @param t
     */
    void setTexture(const BoostType& t);
};

#endif // BOOST_H
