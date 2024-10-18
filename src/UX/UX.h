//
// Created by MPAH on 18/10/2024.
//

#ifndef UX_H
#define UX_H
#include <list>


class Ship;

class UX {
    public:
        static void questionPosition(int &x, int &y);
        static void questionAddShip(int &chosenShip, const std::list<Ship> &Ships);
};



#endif //UX_H
