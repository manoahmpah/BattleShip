#include <iostream>
#include <utility>
#include <unistd.h>
#include <random>

#include "Player.h"
#include "Board.h"
#include "Fleet.h"
#include "Art.h"
#include "UX.h"
#include "Color.h"

Player::Player(std::string  Name)
    : _name(std::move(Name)), _playerBoard(10) {
    _playerBoard.createBoard();
    _autoPlay = false;
}

void Player::setAutoPlay(const bool autoPlay) {
    _autoPlay = autoPlay;
}
Board& Player::getBoard() {
    return _playerBoard;
}
void Player::displayBoard() const {
    std::cout << _playerBoard << std::endl;
}
void Player::hideBoard() const {
    _playerBoard.hideBoard();
}
void Player::placeAuto() {
    _playerBoard.placeAutomatically(_playerFleet);
}
void Player::createBoard() {
    _playerBoard.createBoard();
}
void Player::hideBoard() {
    _playerBoard.hideBoard();
}
bool Player::placeShip(const int x, const int y, Ship &ship) const {
    if (!_playerBoard.errorPosition(x, y, ship)) {
        return false;
    }

    if (ship.getIsHorizontal() && _playerBoard.getCellHidden(x, y)) {
        for(int i = 0; i < ship.getSize(); i++) {
            _playerBoard.setCellHidden(x, y + i, false);
            _playerBoard.setShip(x, y + i, ship);
        }

    } else if (!ship.getIsHorizontal() && _playerBoard.getCellHidden(x, y)) {
        for (int i = 0; i < ship.getSize(); i++) {
            _playerBoard.setCellHidden(x + i, y, false);
            _playerBoard.setShip(x + i, y, ship);
        }
    }

    return true;
}
void Player::placeShips() {
    int x; int y;
    int chosenShip;

    system("cls");
    std::cout << "     ========= " << _name << " =========" << std::endl;
    std::cout << _playerBoard << std::endl;
    int numberShipsPosed = 0;
    while (numberShipsPosed < _playerFleet.getSize()) {
        numberShipsPosed++;
        UX::questionAddShip(chosenShip, _playerFleet.getShips());

        // ======== Check if player choose a right ship ======== //
        if (chosenShip < 1 || chosenShip > _playerFleet.getSize()) {
            Art::invalidOption();
            continue;
        }

        const auto ship = _playerFleet.getShip(chosenShip - 1);

        /* ======== If ship is already posed ======== */
        if (ship->getIsPosed()) {
            system("cls");
            Art::shipAlreadyPlaced();
            std::cout << std::endl;
            std::cout << "     ========= " << _name << " =========" << std::endl;
            std::cout << _playerBoard << std::endl;
            std::cout << std::endl;
            continue;
        }

        UX::questionPosition(x, y);

        if (0 > x >= _playerBoard.getSize() || 0 > y >= _playerBoard.getSize()) {
            system("cls");
            Art::invalidOption();
            std::cout << "     ========= " << _name << " =========" << std::endl;
            std::cout << _playerBoard << std::endl;
            continue;
        }

        /* ======== If the place of the Ship is already occupied ========  */
        if (!placeShip(x - 1, y - 1, *ship)) {
            system("cls");
            Art::invalidOption();

            std::cout << "     ========= " << _name << " =========" << std::endl;
            std::cout << _playerBoard << std::endl;
            continue;
        }

        ship->setIsPosed(true);
        system("cls");
        std::cout << "     ========= " << _name << " =========" << std::endl;
        std::cout << _playerBoard << std::endl;
    }
    system("cls");
}


/* =========== Getter =========== */
std::string Player::getName() const {
    return _name;
}
bool Player::getAutoPlay() const {
    return _autoPlay;
}
int Player::getNumberShipsSunken() const {
    return _playerBoard.getNumberShipsSunken();
}
size_t Player::getFleetSize() const {
    return _playerFleet.getSize();
}

void Player::hitCell(const int x, const int y) {
    if (x < 0 || x >= _playerBoard.getSize() || y < 0 || y >= _playerBoard.getSize()) {
        std::cout << "Position out of range" << std::endl;
        return;
    }
    if (_playerBoard.getShip(x, y) == nullptr) {
        std::cout << "======= Miss =======" << std::endl;
        std::cout << _playerBoard.getStat(x, y) << std::endl;
        _playerBoard.setCellStat(x, y, "o");
        _playerBoard.setCellHidden(x, y, false);

    /* =========== ship about to sink =========== */
    }else if(_playerBoard.getShipSize(x, y) == 1 && _playerBoard.getStat(x, y) != "x") {
        _playerBoard.setCellSunken(x, y, true);
        _playerBoard.addNumberShipsSunken();
        _playerBoard.setCellStat(x, y, "X");
        _playerBoard.decrementShipSize(x, y);
        _playerBoard.setCellHidden(x, y, false);

    /* =========== boat touch =========== */
    }else if (_playerBoard.getShip(x, y) != nullptr && _playerBoard.getStat(x, y) != "x") {
        _playerBoard.setCellHit(x, y, true);
        _playerBoard.setCellStat(x, y, "x");
        _playerBoard.decrementShipSize(x, y);
        _playerBoard.setCellHidden(x, y, false);

    }
}

void Player::autoHitCell() {
    if (!_autoPlay) {
        throw std::logic_error("Player is not in auto play mode");
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distribution(0, _playerBoard.getSize() - 1);
    const int x = distribution(generator);
    const int y = distribution(generator);

    hitCell(x, y);
}

Fleet& Player::getFleet() {
    return _playerFleet;
}