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
    : name(std::move(Name)), playerBoard(10),
      opponentBoard(Board(10)) {
    playerBoard.createBoard();
    autoPlay = false;
}

void Player::setOpponentBoard(const Board &board) {
    opponentBoard = board;
}

Board& Player::getBoard() {
    return playerBoard;
}

void Player::displayBoard() const {
    std::cout << playerBoard << std::endl;
}

Player& Player::operator=(const Player &player) {
    if (this != &player) {
        name = player.name;
        playerBoard = player.playerBoard;
        playerFleet = player.playerFleet;
        autoPlay = player.autoPlay;
    }
    return *this;
}


bool Player::placeShip(const int x, const int y, Ship &ship) const {
    if (!playerBoard.errorPosition(x, y, ship)) {
        return false;
    }

    if (ship.getIsHorizontal() && playerBoard.getCellHidden(x, y)) {
        for(int i = 0; i < ship.getSize(); i++) {
            playerBoard.setCellHidden(x, y + i, false);
            playerBoard.setShip(x, y + i, ship);
        }

    } else if (!ship.getIsHorizontal() && playerBoard.getCellHidden(x, y)) {
        for (int i = 0; i < ship.getSize(); i++) {
            playerBoard.setCellHidden(x + i, y, false);
            playerBoard.setShip(x + i, y, ship);
        }
    }

    return true;
}

void Player::PlaceShips() {
    int x; int y;
    int chosenShip;

    system("cls");
    std::cout << " ========= " << name << " =========" << std::endl;
    std::cout << playerBoard << std::endl;
    int numberShipsPosed = 0;
    while (numberShipsPosed < playerFleet.getSize()) {
        numberShipsPosed++;
        UX::questionAddShip(chosenShip, playerFleet.getShips());

        // ======== Check if player choose a right ship ======== //
        if (chosenShip < 1 || chosenShip > playerFleet.getSize()) {
            std::cout << "Invalid ship" << std::endl;
            continue;
        }

        UX::questionPosition(x, y);

        const auto ship = playerFleet.getShip(chosenShip - 1);
        if (ship->getIsPosed()) {
            system("cls");
            std::cout << std::endl;
            std::cout << getColorCode(Color::RED) << "Ship already posed" << getColorCode(Color::RESET) << std::endl;
            std::cout << std::endl;
            std::cout << playerBoard << std::endl;
            std::cout << std::endl;
            continue;
        }
        ship->setIsPosed(true);

        if (!placeShip(x - 1, y - 1, *ship)) {
            std::cout << playerBoard << std::endl;
            continue;
        }

        system("cls");
        std::cout << " ========= " << name << " =========" << std::endl;
        std::cout << playerBoard << std::endl;
    }
}

std::string Player::getName() const {
    return name;
}

void Player::gameMode()  {

    system("cls");
    std::cout << " ======= All ships placed =======" << std::endl;
    std::cout << std::endl;
    playerBoard.hideBoard();
    std::cout << playerBoard << std::endl;

    while (playerBoard.getNumberShipsSunken() < playerFleet.getSize()) {
        int x; int y;
        UX::questionPosition(x, y);
        hitCell(x - 1, y - 1);
        system("cls");
        std::cout << playerBoard << std::endl;
    }
    Art::gameOver();
    sleep(3);
}

void Player::hitCell(const int x, const int y) {
    if (x < 0 || x >= playerBoard.getSize() || y < 0 || y >= playerBoard.getSize()) {
        std::cout << "Position out of range" << std::endl;
        return;
    }
    if (playerBoard.getShip(x, y) == nullptr) {
        std::cout << "======= Miss =======" << std::endl;
        std::cout << playerBoard.getStat(x, y) << std::endl;
        playerBoard.setCellStat(x, y, "o");
        playerBoard.setCellHidden(x, y, false);
    }else if(playerBoard.getShipSize(x, y) == 1 && playerBoard.getStat(x, y) != "x") {
        playerBoard.setCellSunken(x, y, true);
        playerBoard.addNumberShipsSunken();
        playerBoard.setCellStat(x, y, "X");
        playerBoard.decrementShipSize(x, y);
        playerBoard.setCellHidden(x, y, false);
    }else if (playerBoard.getShip(x, y) != nullptr && playerBoard.getStat(x, y) != "x") {
        playerBoard.setCellHit(x, y, true);
        playerBoard.setCellStat(x, y, "x");
        playerBoard.decrementShipSize(x, y);
        playerBoard.setCellHidden(x, y, false);

    }
}

Fleet& Player::getFleet() {
    return playerFleet;
}