#include "Player.h"
#include "Board.h"
#include "Fleet.h"
#include <iostream>
#include <utility>
#include <unistd.h>

#include "Art.h"
#include "UX.h"
#include "Color.h"

Player::Player(std::string  Name)
    : _name(std::move(Name)), _playerBoard(10),
      _opponentBoard(Board(10)) {
    _playerBoard.createBoard();
    _autoPlay = false;
}

void Player::setOpponentBoard(const Board &board) {
    _opponentBoard = board;
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
    _autoPlay = true;
}

void Player::createBoard() {
    _playerBoard.createBoard();
}

void Player::hideBoard() {
    _playerBoard.hideBoard();
}

Board Player::getOpponentBoard() const {
    return _opponentBoard;
}

void Player::displayOpponentBoard() const {
    std::cout << _opponentBoard << std::endl;
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

void Player::PlaceShips() {
    int x; int y;
    int chosenShip;

    system("cls");
    std::cout << " ========= " << _name << " =========" << std::endl;
    std::cout << _playerBoard << std::endl;
    int numberShipsPosed = 0;
    while (numberShipsPosed < _playerFleet.getSize()) {
        numberShipsPosed++;
        UX::questionAddShip(chosenShip, _playerFleet.getShips());

        // ======== Check if player choose a right ship ======== //
        if (chosenShip < 1 || chosenShip > _playerFleet.getSize()) {
            std::cout << "Invalid ship" << std::endl;
            continue;
        }

        UX::questionPosition(x, y);

        const auto ship = _playerFleet.getShip(chosenShip - 1);
        if (ship->getIsPosed()) {
            system("cls");
            std::cout << std::endl;
            std::cout << getColorCode(Color::RED) << "Ship already posed" << getColorCode(Color::RESET) << std::endl;
            std::cout << std::endl;
            std::cout << _playerBoard << std::endl;
            std::cout << std::endl;
            continue;
        }
        ship->setIsPosed(true);

        if (!placeShip(x - 1, y - 1, *ship)) {
            std::cout << _playerBoard << std::endl;
            continue;
        }

        system("cls");
        std::cout << " ========= " << _name << " =========" << std::endl;
        std::cout << _playerBoard << std::endl;
    }
}

std::string Player::getName() const {
    return _name;
}

void Player::gameMode()  {

    system("cls");
    std::cout << " ======= All ships placed =======" << std::endl;
    std::cout << std::endl;
    _playerBoard.hideBoard();
    std::cout << _playerBoard << std::endl;

    while (_playerBoard.getNumberShipsSunken() < _playerFleet.getSize()) {
        int x; int y;
        UX::questionPosition(x, y);
        hitCell(x - 1, y - 1);
        system("cls");
        std::cout << _playerBoard << std::endl;
    }
    Art::gameOver();
    sleep(3);
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
    }else if(_playerBoard.getShipSize(x, y) == 1 && _playerBoard.getStat(x, y) != "x") {
        _playerBoard.setCellSunken(x, y, true);
        _playerBoard.addNumberShipsSunken();
        _playerBoard.setCellStat(x, y, "X");
        _playerBoard.decrementShipSize(x, y);
        _playerBoard.setCellHidden(x, y, false);
    }else if (_playerBoard.getShip(x, y) != nullptr && _playerBoard.getStat(x, y) != "x") {
        _playerBoard.setCellHit(x, y, true);
        _playerBoard.setCellStat(x, y, "x");
        _playerBoard.decrementShipSize(x, y);
        _playerBoard.setCellHidden(x, y, false);

    }
}

Fleet& Player::getFleet() {
    return _playerFleet;
}