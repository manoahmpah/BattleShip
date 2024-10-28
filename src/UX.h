#ifndef UX_H
#define UX_H
#include <vector>


class Ship;

class UX {
    public:
        static void questionPosition(int &x, int &y);
        static void questionAddShip(int &chosenShip, const std::vector<Ship> &Ships);
};

#endif
