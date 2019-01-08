#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>
#include <QMap>

class Tank : public QGraphicsObject
{
    Q_OBJECT

public:
    //TODO Ivana: implementirati
    Tank(int id);
    ~Tank();
    Tank(const Tank& other);

    //NOTE za dogovor: sta da radim sa brzinom metka? Da ima boost-zvezdica posebno i za to ili
    //da su f,g i r brzi a prva tri spora?

    //NOTE for Nenad: ovo treba isproveravati pri skidanju sloja
    //sa prepreke na sudar sa pucnjem
    enum Weapon{
        gun,        //cigla (1 sloj)
        d,          //cigla (2 sloja)
        e,          //cigla (4 sloja) + beton (1 sloj)
        f,          //cigla (4 sloja) + beton (2 sloja)
        g,          //cigla (4 sloja) + beton (4 sloja)
        r           //cigla (4 sloja) + beton (4 sloja) + cisti sumu
    };

    /*!
     * \brief onShot should be called every time
     * the tank is shoted by opponent.
     * \details change resistant and destroy tank if
     * its resistant become 0.
     */
    void onShot();

    void setSpeed(qreal);

    Weapon getWeapon();
    void setWeapon(const Weapon& newWeapon);


protected:
    int _resistent;
    qreal _speed; //!< should be incremented/decremented when get boost

    //TODO Ivana: razmotri pravljenje posebne klase za oruzje
    Weapon _weapon;
    bool _isManual;

    qreal _x;
    qreal _y;
    int _size = 50; //!< consider making it const

    QMap<QString, QPixmap> _icons;
    QString _activeIcon;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void onUp();
    void onDown();
    void onLeft();
    void onRight();
};

#endif // TANK_H
