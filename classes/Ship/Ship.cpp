//
// Created by MPAH on 15/10/2024.
//

#include "Ship.h"
Ship::Ship(int idShip, const std::string &nameShip, const bool &isShipHorizontal, int sizeShip, bool &isPosed) {
    isHit = false;
    isSunk = false;
    isPosed = false;

    name = nameShip;
    size = sizeShip;
    isHorizontal = isShipHorizontal;
    id = idShip;
}

bool Ship::operator==(const Ship &ship) const {
    return name == ship.name;
}