#ifndef BOOST_H
#define BOOST_H

#include <QGraphicsObject>
#include <QRandomGenerator>

class Boost
{
public:
    Boost();

    ~Boost();

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

    /*!
     * \brief setters and getters...
     */

    void setPowerup(const BoostType& value);
    BoostType getPowerup() const;

    void setX(const int& value);
    int getX() const;

    void setY(const int& value);
    int getY() const;

protected:

    /*!
     * \brief pos_x horisontal position
     * \brief pos_y vertical position
     */
    int pos_x, pos_y;

    BoostType _powerup;
};

#endif // BOOST_H
