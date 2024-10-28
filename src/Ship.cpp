#include "Ship.h"
Ship::Ship(const int idShip, const std::string_view &nameShip, const bool isShipHorizontal, const int sizeShip, const bool isPosed) {
    _isHit = false;
    _isSunk = false;
    _isPosed = isPosed;
    _name = nameShip;
    _size = sizeShip;
    _isHorizontal = isShipHorizontal;
    _id = idShip;
}

bool Ship::operator==(const Ship &ship) const {
    return _name == ship._name;
}

/* =========== Getter =========== */
std::string Ship::getName() const {
    return _name;
}

bool Ship::getIsHit() const {
    return _isHit;
}

bool Ship::getIsSunk() const {
    return _isSunk;
}

bool Ship::getIsPosed() const {
    return _isPosed;
}

int Ship::getId() const {
    return _id;
}

int Ship::getSize() const {
    return _size;
}

bool Ship::getIsHorizontal() const {
    return _isHorizontal;
}

/* =========== Setter =========== */
void Ship::setIsHit(const bool isHit) {
    _isHit = isHit;
}

void Ship::setIsSunk(const bool isSunk) {
    _isSunk = isSunk;
}

void Ship::setIsPosed(const bool isPosed) {
    _isPosed = isPosed;
}

void Ship::setId(const int id) {
    _id = id;
}

void Ship::setSize(const int size) {
    _size = size;
}

void Ship::setIsHorizontal(const bool isHorizontal) {
    _isHorizontal = isHorizontal;
}

void Ship::setName(const std::string_view &name) {
    _name = name;
}