#ifndef IQALGORITHM_H
#define IQALGORITHM_H

/*!
 * \brief The IQAlgorithm class have the algorithm for
 * npc's moving depending on their IQ.
 * \details Since every level should
 * be harder than previews, this class is what makes
 * it possible. Here are the algorithm which determins
 * translation of tanks.
 * Every algorithm has two parts. First one is the base
 * and second part is controler for colisiions.
 * Second part is linked to first, so when choosing
 * algorithm it is enough to specifie only second part.
 */
class IQAlgorithm
{
public:
    IQAlgorithm();

    //opisuje kretanje pri svakom resetovanju skrina
    static void base_mindless(int spead); ///samo ide pravo do kolizije
    //ubaciti i da puca na svakih X milisec
    static void base_thoughtfull(); //ovaj ide do odredjenog cvora i proverava matricu na svakih X milisec

    //static
};

#endif // IQALGORITHM_H
