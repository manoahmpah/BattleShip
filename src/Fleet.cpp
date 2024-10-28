#include "Ship.h"
#include "Fleet.h"

#include <stdexcept>

using namespace std;

void Fleet::addShip(const string &name, const bool isHorizontal, const int size, const bool isSunk) {
    const Ship ship(_ships.back().getId() + 1, name, isHorizontal, size, isSunk);
    _ships.push_back(ship);
}

std::vector<Ship> Fleet::getShips() const {
    return _ships;
}

Ship *Fleet::getShip(const int index) {
    if (index < 0 || index >= _ships.size()) {
        throw out_of_range(" Fleet::getShip Index out of range");
    }
    return &_ships[index];
}

size_t Fleet::getSize() const{
    return _ships.size();
}

void Fleet::setShips(const std::vector<Ship> &ships) {
    _ships = ships;
}