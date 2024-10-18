//
// Created by MPAH on 18/10/2024.
//

#ifndef FLEET_H
#define FLEET_H
#include <list>

#include "Ship.h"


class Fleet {
    public:
        std::list<Ship> Ships = {
            Ship(1, "Aircraft carrier", true, 5, false),
            Ship(2, "Battleship", false, 4, false),
            Ship(3, "Cruiser", true, 3, false),
            Ship(4, "Submarine", true, 3, false),
            Ship(5, "Destroyer", true, 2, false)
        };
        void addShip();

};



#endif //FLEET_H
