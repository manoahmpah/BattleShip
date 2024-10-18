#ifndef SHIP_H
#define SHIP_H
#include <string>


class Ship {
    public:
        Ship(int idShip = 1, const std::string &nameShip = "Empty", const bool &isShipHorizontal = true, int sizeShip = 3, bool isPosed = false);
        std::string state;
        std::string name;
        bool isHit;
        bool isSunk;
        bool isPosed;
        int id;
        int size;
        bool isHorizontal;

        bool operator==(const Ship & ship) const;
};



#endif //SHIP_H
