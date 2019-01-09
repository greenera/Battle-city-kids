#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>
#include <QMap>
#include <QKeyEvent>

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

    /*!
     * \brief setSpeed
     */
    void setSpeed(qreal);

    /*!
     * \brief getWeapon
     * \return Weapon
     */
    Weapon getWeapon();

    /*!
     * \brief setWeapon
     * \param newWeapon
     */
    void setWeapon(const Weapon& newWeapon);

    /*!
     * \brief getSmer
     * \return 1, 2, 3 or 4 depending on wich way tank is
     * faced (Up, Down, Right or Left).
     */
    int getSmer();

    /*!
     * \brief setUp sets indicator if tank is faced to 'up'
     * \param t
     */
    void setUp(bool t);
    void setDown(bool t);
    void setRight(bool t);
    void setLeft(bool t);

    void move();
protected:
    int _moving;           //!< do tank is moving (0 -not, 1 - hoizontal, 2 - vertical)
    int _resistent;         //!< how many times can survive bullet
    qreal _speed;           //!< should be incremented/decremented when get boost
    Weapon _weapon;
    bool _isManual;         //!< indicates if more then one bullet can be projected at the same time
    qreal _x;               //!< x coordinate
    qreal _y;               //!< y coordinate
    const int _size = 50;   //!< size of tank (width and heigh)
    QMap<QString, QPixmap> _icons; //!< icons for every 'smer'
    QString _activeIcon;    //!< active 'smer'

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void vertical();
    void horizontal();
};

#endif // TANK_H
