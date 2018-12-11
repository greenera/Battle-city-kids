#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>

class Tank : public QGraphicsObject
{
    Q_OBJECT

public:
    //TODO Ivana: implementirati
    Tank();
    ~Tank();
    Tank(const Tank& other);

    /*!
     * \brief The Resistant enum
     * how many times can survive bullet
     */
    enum Resistant {
        Weak,           //!< 0 times
        Protected,      //!< 1 time
    };

    /*!
     * \brief The Speed enum
     * speed of movement
     */
    enum Speed{
        slow,
        fast,
        rapid
    };

    /*!
     * \brief The WeaponType enum
     * defiines number of bullets that can be
     * projected at the same time
     */
    enum WeaponType{
        manual,         //!< jedan metak u jednom trenutku ispaljen
        automatic       //!< vise metkova ispaljeno u jednom trenutku NOTE:(maks 3)
    };

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

    Resistant resistent;
    Speed speed;

    //TODO Ivana: razmotri pravljenje posebne klase za oruzje
    Weapon weapon;
    WeaponType weapt;
};

#endif // TANK_H
