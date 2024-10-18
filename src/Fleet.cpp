//
// Created by MPAH on 18/10/2024.
//
#include "Ship.h"

#include "Fleet.h"

void Fleet::addShip() {
    const Ship ship(Ships.back().id + 1, "Test", true, 1, false);
    Ships.push_back(ship);

}