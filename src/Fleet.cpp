//
// Created by MPAH on 18/10/2024.
//

#include <list>
#include "Ship.h"
#include "Fleet.h"

using namespace std;

void Fleet::addShip(const string &name, bool isHorizontal, int size, bool isSunk) {
    const Ship ship(Ships.back().id + 1, name, isHorizontal, size, isSunk);
    Ships.push_back(ship);
}