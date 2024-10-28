#include "Cell.h"
#include "Ship.h"

Cell::Cell() {
    std::string stat = " ";
    _isHidden = true;
    _ship = nullptr;
}

Ship *Cell::getShip() const {
    return _ship;
}

std::string Cell::getStat() const{
    return _stat;
}

bool Cell::getIsHidden() const {
    return _isHidden;
}

void Cell::setStat(const std::string_view &stat) {
    _stat = stat;
}

void Cell::setIsHidden(const bool isHidden) {
    _isHidden = isHidden;
}

void Cell::setShip(Ship *ship) {
    _ship = ship;
}


