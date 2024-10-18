#ifndef SHIP_H
#define SHIP_H
#include <string>


class Ship {
    public:
        Ship(int idShip, const std::string &nameShip, bool isShipHorizontal, int sizeShip, bool isposed);
        std::string state;
        std::string name;
        bool isHit;
        bool isSunk;
        bool isPosed;
        int id;
        int size;
        bool isHorizontal;

    private:
        bool operator==(const Ship & ship) const;
};



#endif //SHIP_H
